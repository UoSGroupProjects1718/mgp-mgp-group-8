using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Food : MonoBehaviour
{
    public GameObject food;
    public LevelManager level;

    [Range(0.0f, 6.0f)]
    public float speed;

	// Use this for initialization
	void Start ()
    {
		
	}
	
	// Update is called once per frame
	void Update ()
    {
		
	}
}

public class Sushi : Food
{
    public Sushi()
    {
        
    }
}
