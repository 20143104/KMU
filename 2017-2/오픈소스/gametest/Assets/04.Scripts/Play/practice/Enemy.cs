using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemy : MonoBehaviour
{
    public int HP;
    private Enemy_Data enemyData;
    public ParticleSystem explosion;
    // Use this for initialization  
    void Start()
    {
        enemyData = new Enemy_Data(HP);
    }

    void Update()
    {
        transform.Translate(Vector2.right * -1 * Time.deltaTime);

        if (enemyData.getHP() <= 0)
        {
            Instantiate(explosion, transform.position, Quaternion.identity); // 폭발이펙트

            Destroy(gameObject);
            // 현재 적의 오브젝트를 메모리풀링으로 만들지 않았기 때문에
            // Destroy로 처리합니다.
        }
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        // 부딛히는 collision을 가진 객체의 태그가 "Player Missile"일 경우
        if (collision.CompareTag("PlayerMissile"))
        {
            enemyData.decreaseHP(10);   // 체력을 10 감소
        }
    }
}