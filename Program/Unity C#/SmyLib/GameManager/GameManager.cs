using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : SingletonMonoBehaviour<GameManager>
{
    protected override void Awake()
    {
        base.Awake();
        if (this == null)
            return;
        CloneSceneManager();
        CloneFadeManager();
    }

    private void CloneSceneManager()
    {
        //すでに存在するなら
        if (SceneChangeManager.Instance != null)
            return;
        Instantiate(Resources.Load<GameObject>("Manager/SceneManager"));
    }

    private void CloneFadeManager()
    {
        if (FadeManager.Instance != null)
            return;
        Instantiate(Resources.Load<GameObject>("Manager/FadeCanvas"));
    }
}
