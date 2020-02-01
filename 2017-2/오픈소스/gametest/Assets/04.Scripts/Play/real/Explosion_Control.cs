using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Explosion_Control : MonoBehaviour {

    // Use this for initialization
    public AudioClip Sfx;
    public AudioSource audioSource;


	void Start ()
    {
        audioSource.PlayOneShot(Sfx, 0.9f);
        Invoke("destroy", 0.75f);
	}
    void destroy()
    {    
        Destroy(this.gameObject);
    }

}
