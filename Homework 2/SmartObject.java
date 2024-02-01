//Ömer Deligöz 150120035
//This class create a smart camera object

public abstract class SmartObject {
	private String alias;
	private String macId;
	private String IP;
	private boolean connectionStatus;

	public SmartObject() {
		this.setAlias(alias);
		this.setMacId(macId);
		this.setIP(IP);
		this.setConnectionStatus(connectionStatus);
	}

	public boolean connect(String IP) {
		this.IP = IP;
		this.connectionStatus = true;
		System.out.println(this.getAlias() + " connection established");
		return false;
	}

	public boolean disconnect() {
		this.IP = null;
		this.connectionStatus = false;
		return false;
	}

	public void SmartObjectToString() {
		System.out.println("This is " + this.getClass().getName() + " device " + this.alias + "\n\tMacId: " + this.macId
				+ "\n\tIP: " + this.IP);
	}

	public boolean controlConnection() {
		if (!connectionStatus) {
			System.out.println("This device is not connected. " + this.getClass() + " -> " + this.getAlias());
		}
		return false;
	}

	public abstract boolean testObject();

	public abstract boolean shutDownObject();

	public String getAlias() {
		return alias;
	}

	public void setAlias(String alias) {
		this.alias = alias;
	}

	public String getMacId() {
		return macId;
	}

	public void setMacId(String macId) {
		this.macId = macId;
	}

	public String getIP() {
		return IP;
	}

	public void setIP(String iP) {
		IP = iP;
	}

	public boolean isConnectionStatus() {
		return connectionStatus;
	}

	public void setConnectionStatus(boolean connectionStatus) {
		this.connectionStatus = connectionStatus;
	}

}
