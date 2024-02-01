import java.util.Calendar;
import java.util.Date;

//Ömer Deligöz 150120035
//This class create a smartplug object

public class SmartPlug extends SmartObject implements Programmable {
	private boolean status;
	private Calendar programTime = Calendar.getInstance();
	private boolean programAction;

	public SmartPlug(String alias, String macId) {
		this.setAlias(alias);
		this.setMacId(macId);
	}

	public void turnOn() {
		if (this.isConnectionStatus()) {
			if (this.status) {
				System.out.println("Smart Plug - " + this.getAlias() + " has been already turned on");
			} else {
				System.out.println(
						"Smart Plug - " + this.getAlias() + " is turned on now (Current time: " + printHour() + ")");
				this.status = true;
			}
		}
	}

	public void turnOff() {
		if (this.isConnectionStatus()) {
			if (this.status) {
				System.out.println(
						"Smart Plug - " + this.getAlias() + " is turned off now (Current time: " + printHour() + ")");
				this.status = false;

			} else {
				System.out.println("Smart Plug - " + this.getAlias() + " has been already turned off");
			}
		}
	}

	@Override
	public String toString() {
		return "SmartPlug [status=" + status + ", programTime=" + programTime + ", programAction=" + programAction
				+ "]";
	}

	// This method set the timer of the object with the given amount of seconds.
	@Override
	public void setTimer(int seconds) {
		if (this.isConnectionStatus()) {
			this.programTime = Calendar.getInstance();
			this.programTime.add(Calendar.SECOND, seconds);
			if (this.status) {
				System.out.println("Smart plug - " + this.getAlias() + " will be turned off " + seconds
						+ " seconds later! (Current time: " + printHour() + ")");
				this.programAction = false;
			} else {
				System.out.println("Smart plug - " + this.getAlias() + " will be turned on " + seconds
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

	// This method turn on or turn off the smart plug by checking the programAction property
	@Override
	public void runProgram() {
		if (this.isConnectionStatus()) {
			if (this.programTime != null && this.programTime.getTime().getSeconds() == Calendar.getInstance().getTime().getSeconds()) {
				if (this.programAction) {
					System.out.println("runProgram -> Smart Plug - " + this.getAlias());
					this.turnOn();
				} else {
					System.out.println("runProgram -> Smart Plug - " + this.getAlias());
					this.turnOff();
				}
			}
		}
	}

	// This method test the functionalities of the object by invoking some methods
	@Override
	public boolean testObject() {
		if (this.isConnectionStatus()) {
			System.out.println("Test is starting for SmartPlug");
			this.SmartObjectToString();
			this.turnOn();
			this.turnOff();
			System.out.println("Test completed for SmartPlug\n");
			return true;
		} else {
			return false;
		}
	}

	@Override
	public boolean shutDownObject() {
		if (this.isConnectionStatus()) {
			if (this.status) {
				SmartObjectToString();
				turnOff();
			}
		}
		return false;
	}

	public static String printHour() {
		String result = "";
		result += Calendar.getInstance().getTime();
		return result.substring(11, 19);
	}

	public boolean compareTimes(Calendar programtime) {
		String time = "" + Calendar.getInstance().getTime();
		String currentSecond = time.substring(17, 19);
		String otherTime = "" + programtime.getTime();
		String otherSecond = otherTime.substring(17, 19);

		if (currentSecond.equals(otherSecond)) {
			return true;
		} else {
			return false;
		}
	}
}
