using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class control : MonoBehaviour
{
    static public Vector3 people_position;
    // Start is called before the first frame update
    void Start()
    {
        people_position = gameObject.transform.position;
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey(KeyCode.W))
        {
            gameObject.transform.position += new Vector3(0, 0.1f, 0);
        }
        if (Input.GetKey(KeyCode.A))
        {
            gameObject.transform.position += new Vector3(-0.1f, 0, 0);
        }
        if (Input.GetKey(KeyCode.S))
        {
            gameObject.transform.position += new Vector3(0, -0.1f, 0);
        }
        if (Input.GetKey(KeyCode.D))
        {
            gameObject.transform.position += new Vector3(0.1f, 0, 0);
        }
        people_position = gameObject.transform.position;
    }
}
