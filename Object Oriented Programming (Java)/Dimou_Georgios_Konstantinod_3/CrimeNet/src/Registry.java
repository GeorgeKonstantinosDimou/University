import java.util.ArrayList;
import java.util.Iterator;

public class Registry {

	//an ArrayList of type Suspect containing all the CrimeNet Suspects 
	private ArrayList<Suspect> aSus= new ArrayList<Suspect>();
	//an ArrayList of type Communication containing all the Communications made in the CrimeNet 
	private ArrayList<Communication> aCom = new ArrayList<Communication>();
	
	//method of adding Suspects in the list 
	public void addSuspect(Suspect aSuspect) {
		aSus.add(aSuspect);
	}
	
	//method of adding the Communications in the list
	//also if the Communication Type is a phone call 
	//it adds the 2 numbers in the Partners List 
	public void addCommunication(Communication aCommunication) {
		int position1; //potition1 keeps the position of the Suspect who has the first Number in Phone Call
		int position2; //potition2 keeps the position of the Suspect who has the first Number in Phone Call
		boolean flag1; //flag1 is true only if the first Suspect has been found 
		boolean flag2; //flag2 is true only if the second Suspect has been found 
		
		aCom.add(aCommunication);
		//typeofCommuniacation == 0 if and only if the comm is of type PhoneCall 
		if(aCommunication.typeofCommunication == 0) {
				//for every Communication those variables start from the beginning!
				flag1 = false;
				flag2 = false;
				position1 = 0;
				position2 = 0;
				for(Suspect sus: aSus) {
					if(sus.containsTelNumber(sus.getTelNumbers(), aCommunication.getNum1())) 
						flag1 = true;
					if(sus.containsTelNumber(sus.getTelNumbers(), aCommunication.getNum2()))
						flag2 = true;
					if(flag1 && flag2) { //this condition is true if and only if the 2 suspects has been found so put them on each other partners List
						aSus.get(position1).addPossibleSuspect(aSus.get(position2));
						aSus.get(position2).addPossibleSuspect(aSus.get(position1));
						break;
					}
					if(!flag1) {
						position1++;
					}
					if(!flag2) {
						position2++;
					}
				}
			}
}
	//method which returns the suspect with the most partners
	//getSuspectWithMostPartners v0.1
	public Suspect getSuspectWithMostPartners() {
		int max = 0 ;
		int i = 0;
		int potition = 0;
		
		for(Suspect suspect: aSus) {
			if(suspect.numberOfPartners(suspect) > max)
				max = suspect.numberOfPartners(suspect);
				potition = i;
				i++;
		}
		return aSus.get(potition);
}
	
	//a method which returns the longest duration phone call between 2 given suspects numbers
	//getLongestPhoneCallBetween v0.1
	//fixed the awful complexity!
	public PhoneCall getLongestPhoneCallBetween(String number1, String number2) {
		int max = 0;
		int i = 0;
		int potition = 0;
		ArrayList<PhoneCall> PComs = new ArrayList<PhoneCall>();
		
		for(Communication communication: aCom) {
			//checks if is a phone call 
			if(communication.typeofCommunication == 0) {
				if(communication.getNum1() == number1 && communication.getNum2() == number2) 
					PComs.add((PhoneCall)communication);
			}
		}
		//Compare every Phone Call duration with a max and return the max Com
		for(PhoneCall Pcall: PComs) {
			if(Pcall.getCallDuration() > max) {
				max = Pcall.getCallDuration();
				potition = i;
				i++;
			}
		}
		return PComs.get(potition);
	}
	
	//getMessagedBetween v0.1
	public ArrayList<SMS> getMessagesBetween(String number1, String number2) {
		
		ArrayList<SMS> SComs = new ArrayList<SMS>();
		
		for(Communication communication: aCom) {
			//checks if is a SMS
			if(communication.typeofCommunication == 1) {
				if(communication.getNum1() == number1 && communication.getNum2() == number2) 
					SComs.add((SMS)communication);
			}
		}
		
		//Using iterator to remove an item.
		//Personal Record:(Remember this cause it took a lot of time to deal with it)!!!
		Iterator<SMS> iterator = SComs.iterator();
		
		//if those specific words occur inside those messages return the communication SMS 
		while(iterator.hasNext()) {
			SMS sms = iterator.next();
			if(!(sms.getMessage().contains("Bomb") || sms.getMessage().contains("Attack") || sms.getMessage().contains("Explosives") || sms.getMessage().contains("Gun"))) {
				iterator.remove();
			}	
		}
		return SComs;
	}
	
	public ArrayList<Suspect> getaSus() {
		return aSus;
	}
	
}

	
