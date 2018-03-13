using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AccuracyPopup : MonoBehaviour {

	// A float that starts at 1.
    float timer = 1;

	// Update is called once per frame.
	void Update () {

		// Every second, 1 is removed from the timer float.
        timer -= Time.deltaTime;
		// When the timer equals less that 0, this function is called.
        if (timer <= 0)
        {
			// Destroys the game object that this script is attatched to.
            Destroy(this.gameObject);
        }

	}
}
