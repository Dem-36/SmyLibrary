#define PI 3.14159265359
#define Gravity 9.8

//���_�̃��[���h���W�����߂�
float3 WORLD_POSITION(float4 vertex){
    return mul(unity_ObjectToWorld,vertex);
}

//RimLight�̌v�Z
float UnlitRimLight(float3 normal, float3 worldPos, float rimPower) {
	//�@���x�N�g�����K��
	float3 N = normalize(normal);
	//���_�̃��[���h���W����J�����̈ʒu�̃x�N�g�������߂�
	float3 L = normalize(worldPos.xyz - _WorldSpaceCameraPos.xyz);
	float d = 1 - saturate(abs(dot(N, L)));
	d = pow(d, rimPower);
	return d;
}

//�O���[�X�P�[��
float GrayScale(fixed3 color){
    return color.r*0.6f+color.g*0.1f+color.b*0.1f;
}

//t: ���� a: ���邳�@b: �ڂ��� c: �F�̃X�P�[�����O
//�Q��:http://iquilezles.org/www/articles/palettes/palettes.htm
float3 colorPalette( float t,  float3 a,  float3 b,  float3 c,float3 d) {
    return a + b * cos(PI*2*(c*t + d));
}

//��ʔ�̎擾
float ScreenRatio(){
    return _ScreenParams.x/_ScreenParams.y;
}


//0.0�`y�̒l�Ɏ��܂鐔�l��Ԃ�
float mod(float x, float y) {
	return x - y * floor(x / y);
}


//Twirl:https://docs.unity3d.com/Packages/com.unity.shadergraph@6.9/manual/Twirl-Node.html
void Twirl(float2 UV, float2 Center, float Strength, float2 Offset, out float2 Out)
{
	//�Q�̒��S�����߂�
	float2 delta = UV - Center;
	//�Q�̓����̋��������S�̃x�N�g���̒�����������
	float angle = Strength * length(delta);
	//�A���L���f�X�̗���������x = a*cos()  y = a*sin()
	float x = cos(angle) * delta.x - sin(angle) * delta.y;
	float y = sin(angle) * delta.x + cos(angle) * delta.y;
	//uv�Ƃ��ďo�͂���(Center�Ő^�񒆂ɍ��킹�AOffset�Œ��߂���)
	Out = float2(x + Center.x + Offset.x, y + Center.y + Offset.y);
}

//val�̒l��inMin�`inMax���̏ꍇ�AoutMin�`outMax�̎w�肳�ꂽ�����ɕϊ����ďo�͂���
float remap(float val, float inMin, float inMax, float outMin, float outMax)
{
    return clamp(outMin + (val - inMin) * (outMax - outMin) / (inMax - inMin), outMin, outMax);
}

//�m�[�}���}�b�v���u�����h����(�ȈՔ�)
//���ʂ�UnityCG.cginc��BlendNormals���g��
fixed3 BlendNormal_Simple(fixed3 normal1,fixed3 normal2){
    return normalize(fixed3(normal1.xy + normal2.xy,normal1.z * normal2.z));
}


//SurfaceShader��UnpackScaleNormal��Unlit�ł��g�p�\�ɂ������́B
//��Ƀo���v�}�b�v�̋��x���蓮�Œ����������Ƃ��Ɏg�p
half3 UnpackScaleNormal_Simple(half4 normal,half scale){
    #if defined(UNITY_NO_DXT5nm)
        return normal.xyz * 2 - 1;
    #else
        half3 n;
        n.xy = (normal.wy * 2 - 1);
        #if(SHADER_TARGET >= 30)
            nn.xy *= scale;
        #endif
        n.z = sqrt(1.0 - saturate(dot(n.xy,normal.xy)));
        return n;
    #endif
}

//�X�N���[�����W���擾����
float4 GetScreenPosition(float4 vertex){
    return ComputeScreenPos(vertex);
}

//GrabTexture�Ŏg�p����X�N���[�����W���擾
float4 GetGrabScreenPosition(float4 vertex){
    return ComputeGrabScreenPos(vertex);
}

//GrabTexture��UV���W���擾
half2 GrabTexture_UV(half4 screenPosition){
    return (screenPosition.xy/screenPosition.w) * float2(1, -1) + float2(0, 1);
}

//�~��`�悷��
float DrawCircle(float2 uv,float3 pos,float r,float blur){
    //�������v�Z
    float d = length(uv - pos);
    //�u���[��������
    float c = smoothstep(r,r - blur,d);
    return c;
}

float Period(){
    return 2.0 * PI;
}

//�g�̐U�ꕝ�����߂� �g�����~�����Ƃ��͓�{�ɂ���
float WaveHeight(float waveLength){
    return waveLength / 7.0;
}

//�g���쐬����
float CulcWave(float x,float waveLength){
    float A = WaveHeight(waveLength);
    float s = sin(Period()/waveLength*x-sqrt(Period()*Gravity/waveLength)*_Time.y);
    return A * s;
}

//�g���쐬���� powNum�Ŕg�������߂�
float CulcWave(int powNum,float x,float waveLength){
    float A = WaveHeight(waveLength);
    float s = sin(Period()/waveLength*x-sqrt(Period()*Gravity/waveLength)*_Time.y);
    s = (s + 1) / 2;
    return A * pow(s,powNum);
}

//�ɍ��W�ϊ�
void PolarCoordinates(float2 uv,float2 center,float radialScale,float lengthScale,out float2 Out){
    float2 delta = uv-center;
    float radius = length(delta) * 2 * radialScale;
    float angle = atan2(delta.x , delta.y) * 1.0 / 6.28 * lengthScale;
    Out = float2(radius,angle);
}