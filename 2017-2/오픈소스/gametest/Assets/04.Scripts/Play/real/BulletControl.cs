using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BulletControl : MonoBehaviour {

    public Transform tr;
    public float destroyXpos;
    void OnTriggerEnter2D(Collider2D coll)
    {
        if (coll.CompareTag("Enemy"))
           Destroy(this.gameObject);
    }
    private void Update()
    {
        if(tr.position.x>destroyXpos)
        {
            Destroy(this.gameObject);
        }
    }
}
