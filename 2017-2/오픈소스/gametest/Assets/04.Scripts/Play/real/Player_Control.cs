using System;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Player_Control : MonoBehaviour
{
    public float Speed = 3f;
    public Transform tr;  //플레이어의 위치값

    public int hp = 10;
    public int initHp = 10;
    public GameObject effect;

    private void Awake()
    {
        hp = initHp;
    }
    void Update()
    {
        /////////////////////////Y값에 대한 /////////////////////
        float size = Camera.main.orthographicSize;
        float offset = 0.9f;
        if (tr.position.y >= size - offset)
        {
            tr.position = new Vector3(tr.position.x, size - offset, 0);
        }
        if (tr.position.y <= -(size - offset))
        {
            tr.position = new Vector3(tr.position.x, -(size - offset), 0);
        }
        /////////////////////////////////////////////////////
        float ScreenRation = (float)Screen.width / (float)Screen.height;
        float Wsize = Camera.main.orthographicSize * ScreenRation; // 가로 사이즈

        if (tr.position.x >= Wsize - offset)
        {
            tr.position = new Vector3(Wsize - offset, tr.position.y, 0);
        }
        if (tr.position.x <= -(Wsize - offset))
        {
            tr.position = new Vector3(-(Wsize - offset), tr.position.y, 0);
        }
        // 매 프레임마다 메소드 호출
        Move();
        
    }
    // 움직이는 기능을 하는 메소드
    private void Move()
    {
        if (Input.GetKey(KeyCode.UpArrow))  // ↑ 방향키를 누를 때
        {
            // Translate는 현재 위치에서 ()안에 들어간 값만큼 값을 변화시킨다.
            transform.Translate(Vector2.up * Speed * Time.deltaTime);
            // Time.deltaTime은 모든 기기(컴퓨터, OS를 망론하고)에 같은 속도로 움직이도록 하기 위한 것
        }
        if (Input.GetKey(KeyCode.DownArrow))  // ↓ 방향키를 누를 때
        {
            transform.Translate(Vector2.down * Speed * Time.deltaTime);
        }
        if (Input.GetKey(KeyCode.RightArrow))  // → 방향키를 누를 때
        {
            transform.Translate(Vector2.right * Speed * Time.deltaTime);
        }
        if (Input.GetKey(KeyCode.LeftArrow))  // ← 방향키를 누를 때
        {
            transform.Translate(Vector2.left * Speed * Time.deltaTime);
        }
    }

    void OnTriggerEnter2D(Collider2D coll)
    {
        if (coll.CompareTag("EnemyMissile"))
            hp--;
        if (coll.CompareTag("Enemy"))
            hp -= 2;
        if (hp <= 0)
        {
            Manager.life--;
            Instantiate(effect, tr.position, Quaternion.identity);
            Debug.Log("Player Die");
        }
    }
}