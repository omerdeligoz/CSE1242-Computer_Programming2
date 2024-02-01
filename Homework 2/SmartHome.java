import java.util.ArrayList; 
import java.util.Arrays;
import java.util.Comparator;
import java.util.Iterator;
import java.util.List;
import java.lang.*;

//Ömer Deligöz 150120035
//This class create a Smart Home object

public class SmartHome {
	private ArrayList<SmartObject> smartObjectList = new ArrayList<>();

	// No arg constructor
	public SmartHome() {
	}

	// This method adds the given smartObject to the smartObjectList
	public boolean addSmartObject(SmartObject smartObject) {
		smartObjectList.add(smartObject);
		int ipValue = 100 + smartObjectList.size() - 1;
		System.out.println("---------------------------------------------------------------------------\n"
				+ "---------------------------------------------------------------------------\n"
				+ "Adding new SmartObject\n"
				+ "---------------------------------------------------------------------------");
		smartObject.connect("10.0.0." + ipValue);
		smartObject.testObject();
		return false;
	}

	// This method removes the given smartObject to the smartObjectList
	public boolean removeSmartObject(SmartObject smartObject) {
		smartObjectList.remove(smartObject);
		return false;
	}

	// This method invoke onCome or onLeave methods
	public void controlLocation(boolean onCome) {
		if (onCome) {
			System.out.println("---------------------------------------------------------------------------\n"
					+ "---------------------------------------------------------------------------\n"
					+ "LocationControl: OnCome\n"
					+ "---------------------------------------------------------------------------");

			for (int i = 0; i < smartObjectList.size(); i++) {
				if (smartObjectList.get(i) instanceof LocationControl) {
					((LocationControl) smartObjectList.get(i)).onCome();
				}
			}

		} else {
			System.out.println("---------------------------------------------------------------------------\n"
					+ "---------------------------------------------------------------------------\n"
					+ "LocationControl: OnLeave\n"
					+ "---------------------------------------------------------------------------");
			for (int i = 0; i < smartObjectList.size(); i++) {
				if (smartObjectList.get(i) instanceof LocationControl) {
					((LocationControl) smartObjectList.get(i)).onLeave();
				}
			}
		}
	}

	// This method invoke controlMotion method
	public void controlMotion(boolean hasMotion, boolean isDay) {
		System.out.println("---------------------------------------------------------------------------\n"
				+ "---------------------------------------------------------------------------\n"
				+ "MotionControl: HasMotion, isDay\n"
				+ "---------------------------------------------------------------------------");

		for (int i = 0; i < smartObjectList.size(); i++) {
			if (smartObjectList.get(i) instanceof MotionControl) {
				((MotionControl) smartObjectList.get(i)).controlMotion(hasMotion, isDay);
			}
		}
	}

	// This method invoke runProgram method
	public void controlProgrammable() {
		System.out.println("---------------------------------------------------------------------------\n"
				+ "---------------------------------------------------------------------------\n"
				+ "Programmable: runProgram\n"
				+ "---------------------------------------------------------------------------");
		for (int i = 0; i < smartObjectList.size(); i++) {
			if (smartObjectList.get(i) instanceof Programmable) {
				((Programmable) smartObjectList.get(i)).runProgram();
			}
		}
	}

	// This method invoke setTimer method according to given seconds
	public void controlTimer(int seconds) {
		System.out.println("---------------------------------------------------------------------------\n"
				+ "---------------------------------------------------------------------------\n"
				+ "Programmable: Timer = " + seconds + " seconds\n"
				+ "---------------------------------------------------------------------------");

		for (int i = 0; i < smartObjectList.size(); i++) {
			if (smartObjectList.get(i) instanceof Programmable) {
				if (seconds > 0) {
					((Programmable) smartObjectList.get(i)).setTimer(seconds);
				} else {
					((Programmable) smartObjectList.get(i)).cancelTimer();
				}
			}
		}
	}

	// This method invoke setTimer method with randomly generated seconds values
	public void controlTimerRandomly() {
		System.out.println("---------------------------------------------------------------------------\n"
				+ "---------------------------------------------------------------------------\n"
				+ "Programmable: Timer = 5 or 10 seconds randomly\n"
				+ "---------------------------------------------------------------------------");

		for (int i = 0; i < smartObjectList.size(); i++) {
			if (smartObjectList.get(i) instanceof Programmable) {
				int random = 5 * (int) (Math.random() * 3);

				if (random != 0) {
					((Programmable) smartObjectList.get(i)).setTimer(random);
				} else {
					((Programmable) smartObjectList.get(i)).cancelTimer();
				}
			}
		}
	}

	// This method sort smart cameras based on the battery life
	public void sortCameras() {
		System.out.println("---------------------------------------------------------------------------\n"
				+ "---------------------------------------------------------------------------\n"
				+ "Sort Smart Cameras\n"
				+ "---------------------------------------------------------------------------");

		int count = 0;
		for (int i = 0; i < smartObjectList.size(); i++) {
			if (smartObjectList.get(i) instanceof SmartCamera) {
				count++;
			}
		}

		// Create Smart Camera array for sorting
		SmartCamera[] cameras = new SmartCamera[count];
		for (int i = 0, j = 0; i < smartObjectList.size(); i++) {
			if (smartObjectList.get(i) instanceof SmartCamera) {
				cameras[j] = (SmartCamera) smartObjectList.get(i);
				j++;
			}
		}

		// Sort smart cameras based on the battery life
		Arrays.sort(cameras);

		// Print sorted array
		for (int i = 0; i < cameras.length; i++) {
			System.out.println(cameras[i]);
		}
	}

	public ArrayList<SmartObject> getSmartObjectList() {
		return smartObjectList;
	}

	public void setSmartObjectList(ArrayList<SmartObject> smartObjectList) {
		this.smartObjectList = smartObjectList;
	}
}
