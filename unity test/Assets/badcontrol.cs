using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class badcontrol : MonoBehaviour
{
    public int hp = 100;
    int cnt = 10;
    System.Random crandom = new System.Random();
    float x, y;
    const float PI = 3.14159265359F;
    public GameObject Bullet;
    // Start is called before the first frame update
    void Start()
    {
        hp = 100;
        gameObject.transform.position = new Vector3(5, -1, 0);
        x = (crandom.Next(0, 6) - 3) / 10;
        y = (crandom.Next(0, 6) - 3) / 10;
    }

    // Update is called once per frame
    void Update()
    {
        if (hp == 0)
        {
            GameObject bullet = Instantiate(Bullet, gameObject.transform.position, gameObject.transform.rotation);
            Vector3 direction;
            Vector3 people_position = control.people_position;
            direction = (people_position - gameObject.transform.position);
            direction.Normalize();
            direction /= 10.0f;
            direction *= 5.0f;
            bullet.GetComponent<bullet>().direction = direction;
            Instantiate(gameObject, new Vector3(5, -1, 0), gameObject.gameObject.transform.rotation);
            Destroy(gameObject);
        }
        if (cnt == 0)
        {
            //print(crandom.Next(0, 6));
            x = (crandom.Next(0, 6) - 3) / 10f;
            y = (crandom.Next(0, 6) - 3) / 10f;
            cnt = 10;
        }
        cnt--;
        gameObject.transform.position += new Vector3(x, y, 0);
    }
    void OnTriggerEnter2D(Collider2D col)
    {
        if (col.tag == "Bullet")
        {
            hp -= 10;
            Destroy(col.gameObject);
        }
    }
}
