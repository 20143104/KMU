using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemy_Control : MonoBehaviour {

    public int hp = 5;
    public int initHp = 5;
    public Transform tr;
    public GameObject effect;
    public float destroyXpos;

    private void OnTriggerEnter2D(Collider2D coll)
    {
        if (coll.CompareTag("PlayerMissile"))
            hp--;


        if (coll.CompareTag("PlayerShortMissile"))
            hp -= 3;
        if (hp <= 0)
        {
            Manager.score += 100;

            Instantiate(effect, tr.position, Quaternion.identity);
            Destroy(this.gameObject);

        }
    }


        private void Update()
    {
        if (tr.position.x < destroyXpos)
        {
            Destroy(this.gameObject);
        }
    }
}
