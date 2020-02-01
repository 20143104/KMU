using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class PauseGame : MonoBehaviour {

    // Use this for initialization
    bool Pause = false;
    public Text TextObj;


    // Update is called once per frame
    void Update ()
    {


        if (Pause == false)
        {
            Time.timeScale = 1;
            TextObj.text = "";
        }
        else
        {
            TextObj.text = "PAUSE";
            Time.timeScale = 0;
        }
        

        if (Input.GetKeyDown("p"))
        {

            if (Pause == true)
                 Pause = false;
             else
                 Pause = true;
        }
        
        
        
	}
}
