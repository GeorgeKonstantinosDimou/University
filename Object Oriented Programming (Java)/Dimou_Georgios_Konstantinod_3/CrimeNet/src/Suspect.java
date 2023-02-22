import java.util.ArrayList;
import java.util.Iterator;

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
		if(!(this.partnersInCrime.contains(aPossiblePartner))) 
			partnersInCrime.add(aPossiblePartner);
	}
	
	//method isConnectedTo, takes a Suspect and returns True if the Suspects
	//are connected else False 
	public boolean isConnectedTo(Suspect aSuspect) { 
		return(partnersInCrime.contains(aSuspect));
	}
		
	//this method takes as a parameter another Suspect and returns a List
	//of all the common Possible Partners between the 2 Suspects
	//getCommonPartners v0.2
	public ArrayList<Suspect> getCommonPartners(Suspect aSuspect) {
		
		Iterator<Suspect> iterator1 = this.possibleCommonPartners.iterator();
		Iterator<Suspect> iterator2 = aSuspect.possibleCommonPartners.iterator();
		
		//remove all the previous context of the possibleCommonPartners List 
		while(iterator1.hasNext()) {
			Suspect suspect1 = iterator1.next();
			iterator1.remove();
		}
		
		while(iterator2.hasNext()) {
			Suspect suspect2 = iterator2.next();
			iterator2.remove();
		}
		
			for(Suspect suspect2: aSuspect.partnersInCrime) {	
				if(this.partnersInCrime.contains(suspect2))
					this.possibleCommonPartners.add(suspect2);
					aSuspect.possibleCommonPartners.add(this);
			}
		return this.possibleCommonPartners;
	}
	
	//printInfo v0.1
	public void printInfo() {
		for(Suspect suspect: partnersInCrime) {
			System.out.println("The Suspect's Partners names are: " + suspect.getName());
			System.out.println("The Suspect's Partners code names are: " + suspect.getCodeName());
		}
	}
	
	public String getName() {
		return name;
	}
	
	public String getCodeName() {
		return codeName;
	}
		
	//method which returns a List with all the telephone numbers
	public ArrayList<String> getTelNumbers() {
		return this.telNumbers;
	}
	
	//method which returns a boolean type depending on if my ArrayList contains a specific telephone number
	public boolean containsTelNumber(ArrayList<String> telNumbers, String atelphone) {
		boolean flag = false;
		int i = 0;
		
		while(!(flag) && i < telNumbers.size() ) {
			if(telNumbers.get(i) == atelphone) {
				flag = true;
			}
			else 
				i++;
		}
		return flag;
	}	
	
	//this method returns the number of partners each suspect has
	//numberOfPartners v0.1
	public int numberOfPartners(Suspect partners) {
		int counter=0;
		for(Suspect partner: partners.partnersInCrime) {
			counter++;
		}
		return counter;
	}
	
	//this method takes 2 suspects and returns the suggested suspects based on the triangular closure principle 
	public ArrayList<Suspect> suggestedSupects(Suspect aSuspect){
		ArrayList<Suspect> suggestedSuspects = new ArrayList<>();
		
		//for every sus search the given Suspects(aSuspect) partnerInCrime list, if the sus is the same as the object which 
		//the method was called upon dont add it on the suggestedSuspectsList. Also if we already have the suspect on out commonPartner list
		//dont add him either.
		for(Suspect sus: aSuspect.partnersInCrime){
			if(!(sus.equals(this) ))
				suggestedSuspects.add(sus);
		}
		return suggestedSuspects;
	}
}


