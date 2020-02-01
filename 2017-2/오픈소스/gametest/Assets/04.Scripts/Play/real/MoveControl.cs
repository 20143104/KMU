using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MoveControl : MonoBehaviour {


    public Transform tr;
    public float speed = 10f;
    // Update is called once per frame
    void Start()
    {
            
    }
    
    void Update ()
    {
        tr.Translate(Vector3.right * speed * Time.deltaTime);
        
	}
}
