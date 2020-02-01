using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FireControl : MonoBehaviour {


    public GameObject[] pos;
    public GameObject bullet;
    public float FireDelay;             // 미사일 발사 속도(미사일이 날라가는 속도x)
    private bool FireState;             // 미사일 발사 속도를 제어할 변수

    public GameObject[] Shortpos;
    public GameObject Shortbullet;
    public float ShortFireDelay;
    private bool ShortFireState;

    public AudioClip sfx;
    public AudioSource audioSource;


    void Start()
    {
        FireState = true;
        ShortFireState = true;
    }
    void Update () {
        {
            if(FireState == true)
                Fire();
            if(ShortFireState == true)
                ShortFire();
        }
    }

    void Fire()
    {
        if (FireState)
        {
            if (Input.GetKey("a"))
            {
                StartCoroutine(FireCycleControl());
                audioSource.PlayOneShot(sfx, 0.3f);
                for (int i = 0; i < pos.Length; i++)
                {
                    Instantiate(bullet, pos[i].transform.position, pos[i].transform.rotation);
                }
            }
            
        }
    }
    IEnumerator FireCycleControl()
    {
        // 처음에 FireState를 false로 만들고
        FireState = false;
        // FireDelay초 후에
        yield return new WaitForSeconds(FireDelay);
        // FireState를 true로 만든다.
        FireState = true;
    }
    IEnumerator ShortFireCycleControl()
    {
        // 처음에 FireState를 false로 만들고
        ShortFireState = false;
        // FireDelay초 후에
        yield return new WaitForSeconds(ShortFireDelay);
        // FireState를 true로 만든다.
        ShortFireState = true;
    }
    void ShortFire()
    {
        if (ShortFireState)
        {
            if (Input.GetKey("s"))
            {
                StartCoroutine(ShortFireCycleControl());
                audioSource.PlayOneShot(sfx, 0.3f);
                for (int i = 0; i < pos.Length; i++)
                {
                    Debug.Log("S");
                    Instantiate(Shortbullet, pos[i].transform.position, pos[i].transform.rotation);                        
                }
            }

        }
    }
}
