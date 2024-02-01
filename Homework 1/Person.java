import java.util.Calendar;

public class Person {
	private int id;
	private String firstName;
	private String lastName;
	private byte gender;
	private java.util.Calendar birthDate;
	private byte maritalStatus;
	private boolean hasDriverLicence;
	String genderstr = "";  //???


	public Person(int id, String firstName, String lastName, String gender, Calendar birthDate, String maritalStatus, String hasDriverLicence) {
		this.id = id;
		this.firstName = firstName;
		this.lastName = lastName;
		this.setHasDriverLicence(hasDriverLicence);
		this.setGender(gender);
		this.birthDate = birthDate;
		//		this.getGender();
		this.setMaritalStatus(maritalStatus);
		genderstr = gender;


	}

	/*	public Person(int id, String firstName, String lastName, String gender, Calendar birthDate, String maritalStatus,
			String hasDriverLicence) {
		this.id = id;
		this.firstName = firstName;
		this.lastName = lastName;
		this.birthDate = birthDate;
		this.setHasDriverLicence(hasDriverLicence);
		this.setGender(gender);
		this.setMaritalStatus(maritalStatus);
	}
	 */

	public int getId() {
		return id;
	}


	public void setId(int id) {
		this.id = id;
	}


	public String getFirstName() {
		return firstName;
	}


	public void setFirstName(String firstName) {
		this.firstName = firstName;
	}


	public String getLastName() {
		return lastName;
	}


	public void setLastName(String lastName) {
		this.lastName = lastName;
	}


	public String getGender() {
		String result ="";

		if (gender == 1) 
			result = "Woman";
		else if (gender == 2) 
			result = "Man";

		return result;
	}


	public void setGender(String gender) {
		if (gender.equals("Woman")) 
			this.gender =1;
		else if (gender.equals("Man")) 
			this.gender =2;
	}


	public java.util.Calendar getBirthDate() {
		return birthDate;
	}


	public void setBirthDate(java.util.Calendar birthDate) {
		this.birthDate = birthDate;
	}


	public String getMaritalStatus() {
		String result ="";

		if (maritalStatus == 1) 
			result = "Single";
		else if (maritalStatus == 2) 
			result = "Married";

		return result;
	}



	public void setMaritalStatus(String status) {
		if (status.equals("Single")) 
			this.maritalStatus =1;
		else if (status.equals("Married")) 
			this.maritalStatus =2;
	}


	public String getHasDriverLicence() {
		String result ="";

		if (hasDriverLicence == true) 
			result = "Yes";
		else 
			result = "No";

		return result;
	}


	public void setHasDriverLicence(String info) {
		if (info.equals("Yes")) 
			this.hasDriverLicence =true;
		else if (info.equals("No")) 
			this.hasDriverLicence =false;
	}

	@Override
	public String toString() {
		return "Person [id=" + id + ", firstName=" + firstName + ", lastName=" + lastName + ", gender=" + gender
				+ ", birthDate=" + birthDate + ", maritalStatus=" + maritalStatus + ", hasDriverLicence="
				+ hasDriverLicence + "]";
	}

	
	
	
	
	/*
	@Override
	public String toString() {
		return "Person Info [id=" + id + ", firstName=" + firstName + ", lastName=" + lastName + ", gender=" + genderstr + "]";
	}
*/

}

