﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

// This our base class for all food items, all food item must derive from this class
public class Food : MonoBehaviour
{
    public GameObject food;
    public LevelManager level;

    [Header("Components")]
    public SpriteRenderer sprite;

    [Range(0.0f, 6.0f)]
    public float speed;

    void Start ()
    {
		
	}

    void Update ()
    {
        transform.position += Vector3.right * speed;
	}

    void OnBecameInvisible()
    {
        // TODO: Call destroy food function from level manager
    }
}
