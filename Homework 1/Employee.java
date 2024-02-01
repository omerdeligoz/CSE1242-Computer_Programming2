import java.util.Calendar;

public class Employee extends Person{
	private double salary;
	private java.util.Calendar hireDate;
	private Department department;
	public static int numberofEmployees;  //static ??? 

	public Employee(int id, String firstName, String lastName, String gender, Calendar birthDate, String maritalStatus, String hasDriverLicence, double salary, Calendar hireDate, Department department) {
		super(id, firstName, lastName, gender, birthDate, maritalStatus, hasDriverLicence);
		this.salary = salary;
		this.hireDate = hireDate;
		this.department = department;
		numberofEmployees++;
	}


	public Employee(Person person, double salary, Calendar hireDate, Department department) {
		super(person.getId(), person.getFirstName(), person.getLastName(), person.getGender(), person.getBirthDate(), person.getMaritalStatus(), person.getHasDriverLicence());
		this.salary = salary;
		this.hireDate = hireDate;
		this.department = department;
		numberofEmployees++;
	}

	public double raiseSalary(double percentage) {
		return (this.salary + this.salary * percentage);
	}
	public double raiseSalary(int amount) {
		return (this.salary + amount);
	}

	public double getSalary() {
		return salary;
	}

	public void setSalary(double salary) {
		this.salary = salary;
	}

	public java.util.Calendar getHireDate() {
		return hireDate;
	}

	public void setHireDate(java.util.Calendar hireDate) {
		this.hireDate = hireDate;
	}

	public Department getDepartment() {
		return department;
	}

	public void setDepartment(Department department) {
		this.department = department;
	}

	public int getNumberofEmployees() {
		return numberofEmployees;
	}

	public void setNumberofEmployees(int numberofEmployees) {
		this.numberofEmployees = numberofEmployees;
	}

	@Override
	public String toString() {
		return "Employee [salary=" + salary + ", hireDate=" + hireDate + ", department=" + department + "]";
	}
}

