using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class SceneChangeManager : SingletonMonoBehaviour<SceneChangeManager>
{
    private AsyncOperation async = null;
    private IEnumerator sceneChangeCoroutine = null;
    private Timer timer;

    protected override void Awake()
    {
        base.Awake();
        //一定時間は必ずロードする
        timer = new Timer(1.0f);
    }

    /// <summary>
    /// シーンの読み込み
    /// </summary>
    /// <param name="sceneName">シーン名</param>
    public void Next(string sceneName)
    {
        //連続読み込み防止
        if (sceneChangeCoroutine != null)
            return;
        sceneChangeCoroutine = SceneChange(sceneName);
        StartCoroutine(sceneChangeCoroutine);
    }

    /// <summary>
    /// シーンの読み込み
    /// </summary>
    /// <param name="sceneName"></param>
    /// <returns></returns>
    private IEnumerator SceneChange(string sceneName)
    {
        yield return new WaitWhile(() => !FadeManager.Instance.FadeIn());
        async = SceneManager.LoadSceneAsync(sceneName);
        //シーン読み込みを自動化させない
        async.allowSceneActivation = false;
        FadeManager.Instance.fadeLoading.Initialize(true);
        while (!async.isDone)
        {
            FadeManager.Instance.fadeLoading.Load();
            timer.Update();
            if (timer.IsTime() && !async.allowSceneActivation)
            {
                async.allowSceneActivation = true;
                timer.Initialize();
            }
            yield return new WaitForSeconds(Time.deltaTime);
        }
        FadeManager.Instance.fadeLoading.Initialize(false);
        yield return new WaitWhile(() => !FadeManager.Instance.FadeOut());
        //Fade out後にシーン遷移可能にする
        sceneChangeCoroutine = null;
    }
}
