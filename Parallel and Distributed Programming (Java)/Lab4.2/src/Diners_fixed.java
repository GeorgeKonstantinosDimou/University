public class Diners_fixed {

    static final int numphils = 5;
    static final int sleeptime = 1;
    
    
     public static void main(String[] args) {
       Philosopher_fixed[] phil= new Philosopher_fixed[numphils];
       Fork_fixed[] fork = new Fork_fixed[numphils];

       for (int i =0; i<numphils; ++i)
            fork[i] = new Fork_fixed(i);
       for (int i =0; i<numphils; ++i){
            phil[i] = new Philosopher_fixed(i, (i+1)%numphils, sleeptime,
                        fork[i], fork[(i+1)%numphils]);
            phil[i].start();
       }
    }

}
