import java.util.Calendar;
import java.util.Date;

//Ömer Deligöz 150120035
//This class create a smart light object

public class SmartLight extends SmartObject implements LocationControl, Programmable {

	private boolean hasLightTurned;
	private Calendar programTime;
	private boolean programAction;

	public SmartLight(String alias, String macId) {
		this.setAlias(alias);
		this.setMacId(macId);
	}

	public void turnOnLight() {
		if (this.isConnectionStatus()) {
			if (this.hasLightTurned) {
				System.out.println("Smart Light - " + this.getAlias() + " has been already turned on");
			} else {
				System.out.println(
						"Smart Light - " + this.getAlias() + " is turned on now (Current time: " + printHour() + ")");
				this.hasLightTurned = true;
			}
		}
	}

	public void turnOffLight() {
		if (this.isConnectionStatus()) {
			if (this.hasLightTurned) {
				System.out.println(
						"Smart Light - " + this.getAlias() + " is turned off now (Current time: " + printHour() + ")");
				this.hasLightTurned = false;

			} else {
				System.out.println("Smart Light - " + this.getAlias() + " has been already turned off");
			}
		}
	}

	// This method set the timer of the object with the given amount of seconds.
	@Override
	public void setTimer(int seconds) {
		if (this.isConnectionStatus()) {
			this.programTime = Calendar.getInstance();
			this.programTime.add(Calendar.SECOND, seconds);
			if (this.hasLightTurned) {
				System.out.println("Smart light - " + this.getAlias() + " will be turned off " + seconds
						+ " seconds later! (Current time: " + printHour() + ")");
				this.programAction = false;
			} else {
				System.out.println("Smart light - " + this.getAlias() + " will be turned on " + seconds
						+ " seconds later! (Current time: " + printHour() + ")");
				this.programAction = true;
			}
		}
	}

	// This method cancel the timer of the object
	@Override
	public void cancelTimer() {
		if (this.isConnectionStatus()) {
			this.programTime = null;
		}
	}

	// This method turn on or turn off the light by checking the programAction property
	@Override
	public void runProgram() {
		if (this.isConnectionStatus()) {
			if (this.programTime != null && this.programTime.getTime().getSeconds() == Calendar.getInstance().getTime().getSeconds()) {
				if (this.programAction) {
					System.out.println("runProgram -> Smart Light - " + this.getAlias());
					this.turnOnLight();
				} else {
					System.out.println("runProgram -> Smart Light - " + this.getAlias());
					this.turnOffLight();
				}
			}
		}
	}

	@Override
	public void onLeave() {
		if (this.isConnectionStatus()) {
			System.out.println("On Leave -> Smart Light - " + this.getAlias());
			turnOffLight();
		}
	}

	@Override
	public void onCome() {
		if (this.isConnectionStatus()) {
			System.out.println("On Come -> Smart Light - " + this.getAlias());
			turnOnLight();
		}
	}

	// This method test the functionalities of the object by invoking some methods
	@Override
	public boolean testObject() {
		if (this.isConnectionStatus()) {
			System.out.println("Test is starting for SmartLight");
			this.SmartObjectToString();
			this.turnOnLight();
			this.turnOffLight();
			System.out.println("Test completed for SmartLight\n");
			return true;
		} else {
			return false;
		}

	}

	@Override
	public boolean shutDownObject() {
		if (this.isConnectionStatus() && hasLightTurned) {
			SmartObjectToString();
			turnOffLight();
			return true;
		} else {
			return false;
		}
	}

	public static String printHour() {
		String result = "";
		result += Calendar.getInstance().getTime();
		return result.substring(11, 19);
	}

	public boolean isHasLightTurned() {
		return hasLightTurned;
	}

	public void setHasLightTurned(boolean hasLightTurned) {
		this.hasLightTurned = hasLightTurned;
	}

	public Calendar getProgramTime() {
		return programTime;
	}

	public void setProgramTime(Calendar programTime) {
		this.programTime = programTime;
	}

	public boolean isProgramAction() {
		return programAction;
	}

	public void setProgramAction(boolean programAction) {
		this.programAction = programAction;
	}

	@Override
	public String toString() {
		return "SmartLight [hasLightTurned=" + hasLightTurned + ", programTime=" + programTime + ", programAction="
				+ programAction + "]";
	}
}
