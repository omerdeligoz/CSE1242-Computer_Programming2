import java.util.ArrayList;
import java.util.Calendar;

public class Developer extends RegularEmployee {
	private ArrayList<Project> projects;
	public static int numberOfDevelopers;

	public Developer(int id, String firstName, String lastName, String gender, Calendar birthDate, String maritalStatus, String hasDriverLicence, double salary, Calendar hireDate, Department department, double pScore, ArrayList<Project> p) {
		super(id, firstName, lastName, gender, birthDate, maritalStatus, hasDriverLicence, salary, hireDate, department, pScore);
		this.projects = p;
	}

	public Developer(RegularEmployee re, ArrayList<Project> p) {
		super(re.getId(), re.getFirstName(), re.getLastName(), re.getGender(), re.getBirthDate(), re.getMaritalStatus(), re.getHasDriverLicence(), re.getSalary(), re.getHireDate(), re.getDepartment(), re.getPerformanceScore());
		this.projects = p;
	}

	public boolean addProject(Project s) {
		return projects.add(s);
	}

	public boolean removeProject(Product s) { 	//???
		return projects.remove(s);
	}

	public ArrayList<Project> getProjects() {
		return projects;
	}

	public void setProjects(ArrayList<Project> projects) {
		this.projects = projects;
	}

	public static int getNumberOfDevelopers() {
		return numberOfDevelopers;
	}

	public static void setNumberOfDevelopers(int numberOfDevelopers) {
		Developer.numberOfDevelopers = numberOfDevelopers;
	}

	@Override
	public String toString() {
		return "Developer [projects=" + projects + "]";
	}
	
	



}
