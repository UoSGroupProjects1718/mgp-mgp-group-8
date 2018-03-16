using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class MainMenu : MonoBehaviour
{
	
	// UI button that triggers a function when clicked.
	// The function is shown in the inspector when the button is selected.
    public Button play;
    public Button replay;
    public Button menu;

	// A function that is assigned to a button and called when the button is clicked.
    public void Play()
    {
 		// This loads the scene that is named within the quotations.
        SceneManager.LoadScene("Level");

        // Play sound on button tap
        gameObject.GetComponent<AudioSource>().Play();
    }

    public void Replay()
    {
        SceneManager.LoadScene("Level");
    }

    public void ReturnToMenu()
    {
        SceneManager.LoadScene("MainMenu");
    }
}