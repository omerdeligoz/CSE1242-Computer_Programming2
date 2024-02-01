//Ömer Deligöz 150120035
//This class create a smart camera object

public class SmartCamera extends SmartObject implements MotionControl, Comparable<SmartCamera> {
	private boolean status;
	private int batteryLife;
	private boolean nightVision;

	public SmartCamera(String alias, String macId, boolean nightVision, int batteryLife) {
		this.setAlias(alias);
		this.setMacId(macId);
		this.batteryLife = batteryLife;
		this.nightVision = nightVision;
	}

	// This method start recording
	public void recordOn(boolean isDay) {
		if (this.isConnectionStatus()) {
			if (isDay) {
				if (this.status) {
					System.out.println("Smart Camera - " + this.getAlias() + " has been already turned on");
				} else {
					System.out.println("Smart Camera - " + this.getAlias() + " is turned on now ");
					this.status = true;
				}
			} else {
				if (nightVision) {
					if (this.status) {
						System.out.println("Smart Camera - " + this.getAlias() + " has been already turned on");
					} else {
						System.out.println("Smart Camera - " + this.getAlias() + " is turned on now ");
						this.status = true;
					}
				} else {
					System.out.println(
							"Sorry! Smart Camera - " + this.getAlias() + " does not have night vision feature.");
				}
			}
		}
	}

	// This method stop recording
	public void recordOff() {
		if (this.isConnectionStatus()) {
			if (this.status) {
				System.out.println("Smart Camera - " + this.getAlias() + " is turned off now");
				this.status = false;
			} else {
				System.out.println("Smart Camera - " + this.getAlias() + " has been already turned off");
			}
		}
	}

	// This method start recording if there is a captured motion.
	@Override
	public boolean controlMotion(boolean hasMotion, boolean isDay) {
		if (!hasMotion) {
			System.out.println("Motion not detected!");
		} else {
			System.out.println("Motion detected!");
		}

		if (isDay) {
			recordOn(isDay);
		} else {
			if (nightVision) {
				recordOn(isDay);
			}
		}
		return false;
	}

	// This method test the functionalities of the object by invoking some methods
	@Override
	public boolean testObject() {
		if (this.isConnectionStatus()) {
			System.out.println("Test is starting for SmartCamera");
			SmartObjectToString();
			System.out.println("Test is starting for SmartCamera day time");
			recordOn(true);
			recordOff();
			System.out.println("Test is starting for SmartCamera night time");
			recordOn(false);
			recordOff();
			System.out.println("Test completed for SmartCamera\n");
			return true;
		} else {
			return false;
		}
	}

	// This method check the connection of the object firstly. Then, it should turn off it (if it has been already turned on)
	@Override
	public boolean shutDownObject() {
		if (this.isConnectionStatus()) {
			if (this.status) {
				SmartObjectToString();
				recordOff();
			}
		}
		return false;
	}



	public int compareTo(SmartCamera smartCamera) {
		if (this.batteryLife > smartCamera.batteryLife) {
			return 1;
		} else if (this.batteryLife < smartCamera.batteryLife) {
			return -1;
		} else {
			return 0;
		}
	}

	public boolean isStatus() {
		return status;
	}

	public void setStatus(boolean status) {
		this.status = status;
	}

	public int getBatteryLife() {
		return batteryLife;
	}

	public void setBatteryLife(int batteryLife) {
		this.batteryLife = batteryLife;
	}

	public boolean isNightVision() {
		return nightVision;
	}

	public void setNightVision(boolean nightVision) {
		this.nightVision = nightVision;
	}

	@Override
	public String toString() {
		if (this.status) {
			return "SmartCamera -> " + this.getAlias() + "'s battery life is " + this.batteryLife
					+ " status is recording ";
		} else {
			return "SmartCamera -> " + this.getAlias() + "'s battery life is " + this.batteryLife
					+ " status is not recording ";
		}
	}
}
