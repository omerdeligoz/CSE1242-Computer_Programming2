import java.util.ArrayList;
import java.util.Calendar;

public class SalesEmployee extends RegularEmployee {
	private ArrayList< Product> sales;
	public static int numberOfSalesEmployees;

	public SalesEmployee(int id, String firstName, String lastName, String gender, Calendar birthDate, String maritalStatus, String hasDriverLicence, double salary, Calendar hireDate, Department department, double pScore, ArrayList<Product> s) {
		super(id, firstName, lastName, gender, birthDate, maritalStatus, hasDriverLicence, salary, hireDate, department, pScore);
		this.sales = s;
	}


	public SalesEmployee(RegularEmployee re, ArrayList<Product> s) {
		super(re.getId(), re.getFirstName(), re.getLastName(), re.getGender(), re.getBirthDate(), re.getMaritalStatus(), re.getHasDriverLicence(), re.getSalary(), re.getHireDate(), re.getDepartment(), re.getPerformanceScore());

	}


	public boolean addSale(Product s) {
		return sales.add(s);
	}

	public boolean removeSale(Object s) {
		return sales.remove(s);
	}

	public static int getNumberOfSalesEmployees() {
		return numberOfSalesEmployees;
	}

	public static void setNumberOfSalesEmployees(int numberOfSalesEmployees) {
		SalesEmployee.numberOfSalesEmployees = numberOfSalesEmployees;
	}

	@Override
	public String toString() {
		return "SalesEmployee [sales=" + sales + "]";
	}

}
