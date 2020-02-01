using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemy_Firecontrol : MonoBehaviour
{


    public GameObject[] pos;
    public GameObject bullet;
    public float FireDelay;             // 미사일 발사 속도(미사일이 날라가는 속도x)
    private bool FireState;             // 미사일 발사 속도를 제어할 변수

    void Start()
    {
        FireState = true;
    }
    void Update()
    {
        {
            if (FireState == true)
                Fire();
        }
    }

    void Fire()
    {
        if (FireState)
        {
            if (true)
            {
                StartCoroutine(FireCycleControl());

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
}
