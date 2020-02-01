using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class Manager : MonoBehaviour
{

    public static int score = 0;
    public static int life = 10;
    float TimeSpan;
    float CheckTime;
    bool state;
    
    public GameObject Boss;
    public Transform BossTr;
    public Text LifeText;
    public Text ScoreText;


    void Awake()
    {
        Screen.sleepTimeout = SleepTimeout.NeverSleep; // 핸드폰 화면 안꺼지게
        Screen.SetResolution(600, 1024, true); // 화면 해상도 고정
    }
    // Use this for initialization
    void Start()
    {
        TimeSpan = 0.0f;
        CheckTime = 5.0f;
        state = true;

    }

    // Update is called once per frame
    void Update()
    {
        LifeText.text = "LIFE : " + life.ToString("00");
        ScoreText.text = "SCORE : " + score.ToString("000000");

        TimeSpan += Time.deltaTime;
        if (TimeSpan > CheckTime && state)
        {
            Instantiate(Boss, BossTr.position, Quaternion.identity);
            state = false;
        }
    }
}
