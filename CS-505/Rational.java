//Michael Gould
//CS 505-851
//314-52-087

public class Main {

  public static void main(String[] args) {

    Rational a = new Rational(2, 3);
    Rational b = new Rational(1, 2);

    System.out.println(a + " + " + b + " = " + a.add(b));
    System.out.println(a + " - " + b + " = " + a.sub(b));
    System.out.println(a + " * " + b + " = " + a.mul(b));
    System.out.println(a + " / " + b + " = " + a.div(b));
  }
}

class Rational{

private int numerator;
private int denominator;

public Rational(int numerator, int denominator){

	this.numerator = numerator;
	this.denominator = denominator;
}

private Rational makeDenominatorSame(Rational o){
	
	if(this.denominator == o.denominator)
		return this;
	return new Rational(o.denominator * numerator, o.denominator * denominator);
}
	
public Rational add(Rational o){
	
	Rational tempA = this.makeDenominatorSame(o);
	Rational tempB = o.makeDenominatorSame(this);
	return new Rational(tempA.numerator + tempB.numerator, tempA.denominator);
}

public Rational sub(Rational o){

	Rational tempA = this.makeDenominatorSame(o);
	Rational tempB = o.makeDenominatorSame(this);
	return new Rational(tempA.numerator - tempB.numerator, tempA.denominator);
}

public Rational mul(Rational o){

	return new Rational(numerator * o.numerator, denominator * o.denominator);
}

public Rational div(Rational o){
	
	return new Rational(numerator * o.denominator, denominator * o.numerator);
}

public String toString(){
	
	return "(" + numerator + "/" + denominator + ")";
}
}