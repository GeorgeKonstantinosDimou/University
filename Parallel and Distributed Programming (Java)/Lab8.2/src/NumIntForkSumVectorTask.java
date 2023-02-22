import java.util.concurrent.RecursiveTask;
 
class NumIntForkSumVectorTask extends RecursiveTask<Double> {
 
  private static final int ACCEPTABLE_SIZE = 1000;
  private int start;
  private int stop;
 
  public NumIntForkSumVectorTask( int start, int stop) {
    this.start = start;
    this.stop = stop; 
  }
 
  @Override
  protected Double compute() {
    double count = 0.0;
    int workLoadSize = stop - start;
    if (workLoadSize < ACCEPTABLE_SIZE) {
      String threadName = Thread.currentThread().getName();
      //System.out.printf("Calculation [%d-%d] in Thread %s\n",start,stop,threadName);
      /* do computation */
      for (int i=start; i < stop; ++i) {
          NumIntForkJoin.numberArray[i] = ((double)i+0.5)*NumIntForkJoin.step;
          count += 4.0/(1.0+NumIntForkJoin.numberArray[i] * NumIntForkJoin.numberArray[i]);
      }
    } else {
      int mid = start + workLoadSize / 2;
      NumIntForkSumVectorTask left = new NumIntForkSumVectorTask(start, mid);
      NumIntForkSumVectorTask right = new NumIntForkSumVectorTask(mid, stop);
 
      // fork (push to queue)-> compute -> join
      left.fork();
      double rightResult = right.compute();
      double leftResult = left.join();
      count = leftResult + rightResult;
    }
    return count;
  }
}
