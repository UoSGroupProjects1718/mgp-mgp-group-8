using System.Collections;
using System.Collections.Generic;
using UnityEngine;

// This our base class for all food items, all food item must derive from this class
public class Food : MonoBehaviour
{
    public GameObject food;
    public LevelManager level;

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

// TODO: May need a separate script file for each food class.
// TODO: Implement Prawn class here
// TODO: Implement Dumpling class here

// Salmon inherits all of food behavior from the base class 
public class Salmon : Food
{
    // TODO: We could set speed here

    private void OnBecameInvisible() 
    {
        level.GetComponent<LevelManager>().DestroySalmon();
    }
}

// Nigri inherits all of food behavior from the base class 
public class Nigri : Food
{
    // TODO: We could set speed here

    private void OnBecameInvisible()
    {
        level.GetComponent<LevelManager>().DestroyNigri();
    }
}
