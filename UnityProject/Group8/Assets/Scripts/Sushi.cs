using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Sushi : MonoBehaviour {

    public GameObject sushi;
    public GameObject levelManager;

    // Range allows speed to be set in the inspector, individual for each type of food .
    [Range(0f, 6f)] public float speed;

    private void Start()
    {
        
    }

    // Use this for initialization.
    void Update()
    {

        // Gets the current position, determines the new direction and speed using the "speed" float.
        transform.position += Vector3.right * speed;

    }

    // OnBecameInvisible is called whenever the object this script is attatched to, leaves the camera view.
    public void OnBecameInvisible()
    {
        // This gets the LevelManager and calls the DestroySushi function.
        levelManager.GetComponent<LevelManager>().DestroySushi();
    }
}
