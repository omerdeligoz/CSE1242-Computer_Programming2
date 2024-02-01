import java.util.ArrayList;
import java.util.Calendar;;

public class Manager extends Employee{
	private ArrayList<RegularEmployee> regularEmployees;
	private double bonusBudget;

	public Manager(int id, String firstName, String lastName, String gender, Calendar birthDate, String maritalStatus, String hasDriverLicence,	double salary, Calendar hireDate, Department department,double bonusBudget) {
		super(id, firstName, lastName, gender, birthDate, maritalStatus, hasDriverLicence, salary, hireDate, department);
		this.bonusBudget = bonusBudget;
	}

	public Manager(Employee employee, double bonusBudget) {
		super(employee.getId(), employee.getFirstName(), employee.getLastName(), employee.getGender(), employee.getBirthDate(),	employee.getMaritalStatus(), employee.getHasDriverLicence(), bonusBudget, employee.getHireDate(), employee.getDepartment());
		this.bonusBudget = bonusBudget;
	}

	public void addEmployee(RegularEmployee e) {
		regularEmployees.add(e);

	}

	public void removeEmployee(RegularEmployee e) {
		regularEmployees.remove(e);

	}
	public void distributeBonusBudget() {  //to be continued


	}

	public ArrayList<RegularEmployee> getRegularEmployees() {
		return regularEmployees;
	}

	public void setRegularEmployees(ArrayList<RegularEmployee> regularEmployees) {
		this.regularEmployees = regularEmployees;
	}

	public double getBonusBudget() {
		return bonusBudget;
	}

	public void setBonusBudget(double bonusBudget) {
		this.bonusBudget = bonusBudget;
	}

	@Override
	public String toString() {
		return "Manager [regularEmployees=" + regularEmployees + ", bonusBudget=" + bonusBudget + "]";
	}

}
