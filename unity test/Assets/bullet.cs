using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class bullet : MonoBehaviour
{
    // Start is called before the first frame update
    Vector3 direction = new Vector3(0f, 0f, 0f);
    void Start()
    {
        const float PI = 3.14159265359F;
        float tan = (gameObject.transform.position.y - Input.mousePosition.y) / (gameObject.transform.position.x - Input.mousePosition.x);
        tan = Mathf.Atan(tan) * 180 / PI;
        gameObject.transform.rotation = Quaternion.Euler(gameObject.transform.rotation.x, gameObject.transform.rotation.y, tan + 90 );
        direction = (Input.mousePosition - gameObject.transform.position);
        //print(string.Format("{0} {1} {2}\n", direction.x, direction.y, direction.z));
        direction.Normalize();
        direction /= 10.0f;
        direction *= 5.0f;
        //print(string.Format("{0} {1} {2}\n", direction.x, direction.y, direction.z));
    }

    // Update is called once per frame
    void Update()
    {
        gameObject.transform.position += direction;
		if(gameObject.transform.position.x>15){
			Destroy(gameObject);
		}
    }
}
