using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Food : MonoBehaviour
{
    public GameObject food;
    public LevelManager level;

    [Range(0.0f, 6.0f)]
    public float speed;

    virtual protected void Start ()
    {
		
	}

    virtual protected void Update ()
    {
        transform.position += Vector3.right * speed;
	}

    virtual protected void OnBecameInvisible()
    {
        // TODO: Call destroy food function from level manager
    }
}

public class Salmon : Food
{ 

}

public class Nigri : Food
{

}
