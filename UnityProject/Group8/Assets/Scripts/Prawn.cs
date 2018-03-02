using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Prawn : MonoBehaviour
{
    public GameObject prawn;
    public GameObject levelManager;

	// Range allows speed to be set in the inspector, individual for each type of food.
	[Range(0f, 6f)] public float speed;  

	// Update is called once per frame.
	void Update()
	{
		// Gets the current position, determines the new direction and speed using the "speed" float.
		transform.position += Vector3.right * speed;

	}
    // OnBecameInvisible is called whenever the object this script is attatched to, leaves the cameras view.
    public void OnBecameInvisible()
    {
		// This gets the LevelManager and calls the DestroyPrawn function.
        levelManager.GetComponent<LevelManager>().DestroyPrawn();
    }

}