using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using tool;

public class gunmove : MonoBehaviour
{
    // Start is called before the first frame update
    //public GameObject Obj;
    public GameObject Bullet;
    private Camera camera;
    void Start()
    {
        camera = Camera.main;
    }
    // Update is called once per frame
    void Update()
    {
        Vector3 people_position = control.people_position;
        people_position += new Vector3(1, 0.3f, 0);
        gameObject.transform.position = people_position;
        const float PI = 3.14159265359F;
        float tan = (gameObject.transform.position.y - Input.mousePosition.y) / (gameObject.transform.position.x - Input.mousePosition.x);
        tan = Mathf.Atan(tan) * 180 / PI;
        //gameObject.transform.rotation =  Quaternion.Euler(gameObject.transform.rotation.x, gameObject.transform.rotation.y, tan);
        float angleZ = Mathf.Atan2(Input.mousePosition.y, Input.mousePosition.x) * Mathf.Rad2Deg;
        Vector3 mpos = camera.ScreenToWorldPoint(Input.mousePosition);

        if (Input.GetKeyDown(KeyCode.Space)) 
        {
            Vector3 pos = gameObject.transform.position;
            
            pos.x += 2;
            Vector3 direction;
            direction = (mpos - pos);
            direction.z = 0;
            direction.Normalize();
            //print(direction);
            direction /= 10.0f;
            direction *= 5.0f;
            GameObject new_bullet = Instantiate(Bullet, pos, Quaternion.Euler(gameObject.transform.rotation.x, gameObject.transform.rotation.y, tan ));
            new_bullet.GetComponent<bullet>().direction = direction;
        }
    }
}
