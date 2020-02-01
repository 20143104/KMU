using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class MainManager : MonoBehaviour
{

    // Use this for initialization
    public void OnStartClick()
    {
        SceneManager.LoadScene("Select");
    }
    public void OnEndClick()
    {
        Application.Quit();
    }
    public void OnHelpClick()
    {
        SceneManager.LoadScene("Help");
    }
    public void OnBackClick()
    {
        SceneManager.LoadScene("Main");
    }
    public void OnPlayYasuo()
    {
        SceneManager.LoadScene("Play_Yasuo");
    }
}
