using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class LevelManager : MonoBehaviour
{
    // TODO: Replace with an object pool
	GameObject currentPrawn;
	GameObject currentDumpling;
    GameObject currentSalmon;
    GameObject currentNigri;

	// UI button that trigger a function when clicked.
	// The function is shown in the inspector when the button is selected.
	public Button onePlayer;
    public Button twoPlayer;

	// An array that contains game objects for each type of food that is being spawned. Visible in the inspector.
    public GameObject[] food;

	// The position and rotation of the food spawner location. Visible in the inspector.
	public Transform spawn;

    public GameObject boundary;
    float distanceBetween;
    public float last;

	// UI button that triggers a function when clicked.
	// The function is shown in the inspector when the button is selected.
	public Button narutoOne;
	public Button narutoTwo;

	// Each of these floats hold a score which is then shown as text in the UI.
	// Visible in the inspector for debug purposes.
	public float scorePlayer1;
	public float scorePlayer2;

	// The text that will show the score. Visible in the inspector.
    public Text Player1;
    public Text Player2;

    public Text PlayerOneSpot;
    public Text PlayerTwoSpot;

	// Accuracy popup game objects. Visible in the inspector.
	public GameObject miss;
    public GameObject ok;
    public GameObject good;
    public GameObject excellent;
    public GameObject perfect;

	// The position and rotation of the accuracy popup spawn location. Visible in the inspector.
    public Transform accuracyTop;
    public Transform accuracyBottom;

	// A true or false statement to state which players turn it is.
	// As it starts on true, player one is true and player two is false.
    public bool playerSwap = true;

	// An integer that contains a count of how many turns have been taken.
	// Visible in the inspector for debug purposes.
    public int turnTaking;

    public int foodSent;

    public float timeBetweenClicks = 0.5f;
    private float timestamp;
    private float timestamp2;

    int foodArray = 0;

	public float speedMultiply = 0.1f;

	public int comboPlayerOne;
	public int comboPlayerTwo;

	public GameObject currentDistanceOne;
	public GameObject currentDistanceTwo;

	public Text comboOne;
	public Text comboTwo;

    public int turnRotation;



	// A function that is assigned to a button and called when the button is clicked.
    public void OnePlayerClick()
    {
		// If the parameters of the if statement are met, the function is called.
        if (playerSwap == true && Time.time >= timestamp)
        {
			// Prints the contents of the quotation marks in the console when called.
            Debug.Log("1P");
			// This creates a game object called "newPrawn" using the game object that is set in slot 0 within the food array.
			// It is spawned at a location specified by spawn and given the rotation +180.
			GameObject newPrawn = Instantiate(food[foodArray], spawn.position, Quaternion.Euler(0,0,180));
			// When the "newPrawn" is spawned, it is given the level manager script.
            newPrawn.GetComponent<Prawn>().levelManager = this.gameObject;
            foodSent += 1;
            foodArray += 1;
            timestamp = Time.time + timeBetweenClicks;

            //playerSwap = false;
			//onePlayer.interactable = false;
			//narutoOne.interactable = true;
        }
    }

	// A function that is assigned to a button and called when the button is clicked.
    public void TwoPlayerClick()
    {
        if (playerSwap == false && Time.time >= timestamp2)
        {
            Debug.Log("2P");
			// This creates a game object called "newPrawn" using the game object that is set in slot 0 within the food array.
			// It is spawned at a location specified by spawn and given the rotation of the "spawn" game object.
            GameObject newPrawn = Instantiate(food[foodArray], spawn.position, Quaternion.identity);
            newPrawn.GetComponent<Prawn>().levelManager = this.gameObject;
            foodSent += 1;
            foodArray += 1;
            timestamp2 = Time.time + timeBetweenClicks;
            //playerSwap = true;
            //twoPlayer.interactable = false;
            //narutoTwo.interactable = true;
        }
    }

	// Updated is called once per frame.
    void Update ()
	{

       /* if (currentDistanceOne = null){
            comboPlayerOne = 0;
        }*/

		if (foodArray == 3) {
			foodArray = 0;
		}
		// This sets the text within the UI text box to the float determined by the score floats.
		Player1.text = "" + scorePlayer1;
		Player2.text = "" + scorePlayer2;

		comboOne.text = "" + comboPlayerOne;
        comboTwo.text = "" + comboPlayerTwo;


		if (scorePlayer1 == scorePlayer2) {
			PlayerOneSpot.text = "2nd";
			PlayerTwoSpot.text = "2nd";
		}

		if (scorePlayer2 > scorePlayer1) {
			PlayerTwoSpot.text = "1st";
			PlayerOneSpot.text = "2nd";
		}

		if (scorePlayer2 < scorePlayer1) {
			PlayerTwoSpot.text = "2nd";
			PlayerOneSpot.text = "1st";
		}

		// This sets the last prawn to enter the boundary as the currentPrawn.
		currentPrawn = boundary.GetComponent<boundaryCubeScript> ().currentPrawn;

		// If there is a currentPrawn.
		if (currentPrawn != null) {
			// Sets the distanceBetween variable as the distance between the prawn and the centre of the boundary.
			distanceBetween = Vector3.Distance (currentPrawn.transform.position, boundary.transform.position);
			Debug.Log (distanceBetween);
		}

		// Same as the above comments except currentPrawn is replaced by currentDumpling.
		currentDumpling = boundary.GetComponent<boundaryCubeScript> ().currentDumpling;
		if (currentDumpling != null) {
			distanceBetween = Vector3.Distance (currentDumpling.transform.position, boundary.transform.position);
			Debug.Log (distanceBetween);
		}

		// This if statement is called when 20 turns have been taken and if player one has the highest score.
		if (turnTaking == 50 && scorePlayer1 > scorePlayer2) {
			// When this function is called,
			SceneManager.LoadScene ("PlayerOneWin");
		}

		if (turnTaking == 50 && scorePlayer2 > scorePlayer1) {
			SceneManager.LoadScene ("PlayerTwoWin");
		}

		if (Input.GetKey ("escape")) {
			Application.Quit ();
		}

		if (foodSent == 5 && playerSwap == true) {
			foodSent = 0;
			playerSwap = false;
		}

		if (foodSent == 5 && playerSwap == false) {
			foodSent = 0;
			playerSwap = true;
			//foreach (var item in food) {
				//item.GetComponent<Prawn> ().speed += speedMultiply;
			//}

        }

        if (foodSent == 1 && playerSwap == false)
        {
            //narutoOne.interactable = false;
        }

        if (foodSent == 1 && playerSwap == true)
        {
           // narutoTwo.interactable = false;
        }

        if (playerSwap == true)
        {
            onePlayer.interactable = true;

           twoPlayer.interactable = false;
          //  narutoOne.interactable = true;
        }

        if (playerSwap == false)
        {
            onePlayer.interactable = false;
           // narutoTwo.interactable = true;

            twoPlayer.interactable = true;

        }

        if(turnRotation == 0)
        {
            narutoOne.interactable = true;
            narutoTwo.interactable = false;
        }

        if (turnRotation == 10)
        {
            turnRotation = 0;
        }

        if (turnRotation == 5) {

            narutoTwo.interactable = true;
            narutoOne.interactable = false;

        }

        if (turnRotation == 10)
        {
           // narutoOne.interactable = true;
        }
    }

	// A function that is assigned to a button and called when the button is clicked.
    public void player1Naruto()
    {

        if (currentPrawn == null) { return; }
        last = distanceBetween;


		// When the parameters of this if statement are met, then this function will be called.
        if (distanceBetween < 0.3f)
        {
            // Adds a specified amount to the scorePlayer float.
            scorePlayer1 += 5;
            scorePlayer1 += comboPlayerOne;
			// Spawns the specified accuracy popup, at the specified location and rotation.
			Instantiate(perfect, accuracyTop.position, Quaternion.Euler(0,0,180));
            if (currentDistanceOne == excellent || currentDistanceOne == good)
            {
                comboPlayerOne = 0;
            }
            currentDistanceOne = perfect;
            comboPlayerOne += 1;
            //turnRotation += 1;
        }
        else if (distanceBetween < 1f)
        {
            scorePlayer1 += 3;
            scorePlayer1 += comboPlayerOne;
			Instantiate(excellent, accuracyTop.position, Quaternion.Euler(0,0,180));
            if (currentDistanceOne == perfect || currentDistanceOne == good)
            {
                comboPlayerOne = 0;
            }
            currentDistanceOne = excellent;
            comboPlayerOne += 1;
            //turnRotation += 1;

        }
        else
        {
            scorePlayer1 += 1;
            scorePlayer1 += comboPlayerOne;
			Instantiate(good, accuracyTop.position, Quaternion.Euler(0,0,180));
			if (currentDistanceOne == perfect || currentDistanceOne == excellent)
            {
                comboPlayerOne = 0;
            }

            currentDistanceOne = good;
            comboPlayerOne += 1;
            //turnRotation += 1;

        }
        // Destroys the game object set as currentPrawn.
        turnTaking += 1;
        Destroy(currentPrawn);
    }

	// A function that is assigned to a button and called when the button is clicked.
    public void player2Naruto()
    {
		// If currentDumpling is set to none, returns the type of the function.
        if (currentPrawn == null) { return; }

		//onePlayer.interactable = true;
		//narutoTwo.interactable = false;
        last = distanceBetween;

        if (distanceBetween < 0.3f)
        {
            scorePlayer2 += 5;
            scorePlayer2 += comboPlayerTwo;
			// Spawns the specified accuracy popup, at the specified location and rotation of the accuracyBottom.
            Instantiate(perfect, accuracyBottom.position, Quaternion.identity);
            if (currentDistanceTwo == excellent || currentDistanceTwo == good)
            {
                comboPlayerTwo = 0;

            }
            currentDistanceTwo = perfect;
            comboPlayerTwo += 1;
            //turnRotation += 1;

        }
        else if (distanceBetween < 1f)
        {
            scorePlayer2 += 3;
            scorePlayer2 += comboPlayerTwo;
            Instantiate(excellent, accuracyBottom.position, Quaternion.identity);
            if (currentDistanceTwo == perfect || currentDistanceTwo == good)
            {
                comboPlayerTwo = 0;

            }
            currentDistanceTwo = excellent;
            comboPlayerTwo += 1;
            //turnRotation += 1;

        }
        else
        {
            scorePlayer2 += 1;
            scorePlayer2 += comboPlayerTwo;
			Instantiate(good, accuracyBottom.position, Quaternion.identity);
            if (currentDistanceTwo == perfect || currentDistanceTwo ==  excellent)
            {
                comboPlayerTwo = 0;

            }
            currentDistanceTwo = good;
            comboPlayerTwo += 1;
            //turnRotation += 1;

        }
        // Destroys the game object set as currentDumpling.
        turnTaking += 1;
        Destroy(currentPrawn);
    }

    // Rather than having duplicate methods, we destroy food with one method.
    public void DestroyFood()
    {
        // TODO: Get the current food via the object pool
        // TODO: Switch which player can interact with food
        // TODO: Add turn
    }

    // This function is called via the Prawn script.
    public void DestroyPrawn()
    {
		// Sets the currentPrawn to none.
       currentPrawn = null;
      // twoPlayer.interactable = true;
      // narutoOne.interactable = false;
      // turnTaking += 1;

    }

    public void DestroyDumpling()
    {
		// Sets the currentDumpling to none.
        currentDumpling = null;
      //  onePlayer.interactable = true;
      //  narutoTwo.interactable = false;
      //  turnTaking += 1;

    }

    public void DestroySushi()
    {
        currentSushi = null;

    }

    public void DestroySalmon()
    {
        currentSalmon = null;
        turnTaking += 1;
    }

    public void DestroyNigri()
    {
        currentNigri = null;
        turnTaking += 1;
    }
}
