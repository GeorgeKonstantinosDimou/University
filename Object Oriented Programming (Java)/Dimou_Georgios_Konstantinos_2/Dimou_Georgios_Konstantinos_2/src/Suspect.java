import java.util.ArrayList;

public class Suspect {

	protected String name;
	protected String codeName;
	protected String town;
	private String atelphone;
	private ArrayList<String> telNumbers = new ArrayList<String>();;
	//this Array Contains the CrimePartners for each Suspect 
	private ArrayList<Suspect> partnersInCrime = new ArrayList<Suspect>();
	//this Array Contains the union of possible Partners for 2 different Suspects 
	private ArrayList<Suspect> possibleCommonPartners = new ArrayList<Suspect>();
	
	public Suspect(String name, String codeName, String town) {
		
		this.name = name;
		this.codeName = codeName;
		this.town = town;
		
	}
	
	//method which adds a phone number to the suspects number list
	public void addNumber(String atelnumber) {
		telNumbers.add(atelnumber) ;
	}
	
	//method which adds another suspect on the CrimePartners List
	//if he doesnt already exists there
	public void addPossibleSuspect(Suspect aPossiblePartner) {
		if(!partnersInCrime.contains(aPossiblePartner)) {
			partnersInCrime.add(aPossiblePartner);
		}
	}
	
	//method isConnectedTo, takes a Suspect and returns True if the Suspects
	//are connected else False 
	public boolean isConnectedTo(Suspect aSuspect) {
		return(partnersInCrime.contains(aSuspect));
	}
	
	//this method takes as a parameter another Suspect and returns a List
	//of all the common Possible Partners between the 2 Suspects
	public ArrayList<Suspect> getCommonPartners(Suspect aSuspect) {
		for(int i = 0; i < this.partnersInCrime.size(); i++) {
			for(int j = 0; i < aSuspect.partnersInCrime.size(); j++) {
				if(this.partnersInCrime.get(i).getCodeName() == aSuspect.partnersInCrime.get(j).getCodeName())
					possibleCommonPartners.add(partnersInCrime.get(i));
			}
		}
		return possibleCommonPartners;
	}
	
	public void printInfo() {
		for(int i=0; i < partnersInCrime.size(); i++) {
			System.out.println("The Suspect's Partners names are: " + partnersInCrime.get(i).getName());
			System.out.println("The Suspect's Partners code names are: " + partnersInCrime.get(i).getCodeName());
		}
	}
	
	public String getName() {
		return name;
	}
	
	public String getCodeName() {
		return codeName;
	}
	
	public String getTown() {
		return town;
	}

	public void setTown(String town) {
		this.town = town;
	}

	public void setName(String name) {
		this.name = name;
	}

	public void setCodeName(String codeName) {
		this.codeName = codeName;
	}
	
	//method which returns a List with all the telephone numbers
	public ArrayList<String> getTelNumbers() {
		return telNumbers;
	}
	
	//a method which gives me a specific telephone number
	public String getAtelphone(int i,ArrayList<String> telNumbers) {
		return telNumbers.get(i);
	}
	
	//method which returns a boolean type depending on if my ArrayList contains a specific telephone number
	public boolean containsTelNumber(ArrayList<String> telNumbers, String atelphone) {
		boolean flag = false;
		int i = 0;
		
		while(!(flag) && i <= telNumbers.size() ) {
			if(telNumbers.get(i) == atelphone) {
				flag = true;
			}
			else 
				i++;
		}
		return flag;
	}	
	
	//this method returns the number of partners each suspect has 
	public int numberOfPartners(Suspect partners) {
		int counter=0;
		for(Suspect partner: partnersInCrime) {
			if(partner.containsTelNumber(partners.getTelNumbers(), atelphone)) {
				counter++;
			}
		}
		return counter;
	}
	
	
}
