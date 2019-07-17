﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class control : MonoBehaviour
{
    static public Vector3 people_position;
    public int hp = 100;
    // Start is called before the first frame update
    private Rigidbody2D rb;
    void Start()
    {
        hp = 100;
        gameObject.transform.position = new Vector3(-6, -1, 0);
        people_position = gameObject.transform.position;
        rb = gameObject.GetComponent<Rigidbody2D>();
    }

    // Update is called once per frame
    void Update()
    {
        if (hp == 0)
        {
            Instantiate(gameObject, new Vector3(-6, -1, 0), gameObject.gameObject.transform.rotation);
            Destroy(gameObject);
        }
        if (Input.GetKey(KeyCode.W))
        {
            //gameObject.transform.position += new Vector3(0, 0.1f, 0);
            rb.velocity = Vector3.up * 1;
        }
        if (Input.GetKey(KeyCode.A))
        {
            //gameObject.transform.position += new Vector3(-0.1f, 0, 0);
            rb.velocity = Vector3.left * 1;
        }
        if (Input.GetKey(KeyCode.S))
        {
            //gameObject.transform.position += new Vector3(0, -0.1f, 0);
            rb.AddForce(Vector3.down * 1); ;
        }
        if (Input.GetKey(KeyCode.D))
        {
            //gameObject.transform.position += new Vector3(0.1f, 0, 0);
            rb.velocity = Vector3.right * 1;
        }
        //print(rb.velocity);
        people_position = gameObject.transform.position;
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
