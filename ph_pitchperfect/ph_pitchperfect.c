/*
 * HOWTO write an External for Pure data
 * (c) 2001-2006 IOhannes m zm�lnig zmoelnig[AT]iem.at
 *
 * this is the source-code for the first example in the HOWTO
 * it creates an object that prints "Hello world!" whenever it 
 * gets banged.
 *
 * for legal issues please see the file LICENSE.txt
 */



/**
 * include the interface to Pd 
 */
#include "m_pd.h"

/**
 * define a new "class" 
 */
static t_class *ph_pitchperfect_class;


/**
 * this is the dataspace of our new object
 * we don't need to store anything,
 * however the first (and only) entry in this struct
 * is mandatory and of type "t_object"
 */
typedef struct ph_pitchperfect {
  t_object  x_obj;

  t_float input;

  t_outlet *out_stage_1;
  t_outlet *out_stage_1_3;
  t_outlet *out_stage_1_5;

  t_outlet *out_stage_2;
  t_outlet *out_stage_2_3;
  t_outlet *out_stage_2_5;

  t_outlet *out_stage_3;
  t_outlet *out_stage_3_3;
  t_outlet *out_stage_3_5;

  t_outlet *out_stage_4;
  t_outlet *out_stage_4_3;
  t_outlet *out_stage_4_5;

  t_outlet *out_stage_5;
  t_outlet *out_stage_5_3;
  t_outlet *out_stage_5_5;

  t_outlet *out_stage_6;
  t_outlet *out_stage_6_3;
  t_outlet *out_stage_6_5;

  t_outlet *out_stage_7;
  t_outlet *out_stage_7_3;
  t_outlet *out_stage_7_5;

  t_outlet *out_stage_8;
  t_outlet *out_stage_8_3;
  t_outlet *out_stage_8_5;

} ph_pitchperfect;


/**
 * this method is called whenever a "bang" is sent to the object
 * the name of this function is arbitrary and is registered to Pd in the 
 * helloworld_setup() routine
 */
void ph_pitchperfect_bang(ph_pitchperfect *x)
{
  /*
   * post() is Pd's version of printf()
   * the string (which can be formatted like with printf()) will be
   * output to wherever Pd thinks it has too (pd's console, the stderr...)
   * it automatically adds a newline at the end of the string
   */
	post("Hello Welt !!");
}


/**
 * this is the "constructor" of the class
 * this method is called whenever a new object of this class is created
 * the name of this function is arbitrary and is registered to Pd in the 
 * helloworld_setup() routine
 */
void *ph_pitchperfect_new(t_floatarg param1)
{
  /*
   * call the "constructor" of the parent-class
   * this will reserve enough memory to hold "t_helloworld"
   */
	ph_pitchperfect *x = (ph_pitchperfect *)pd_new(ph_pitchperfect_class);

/**
	x->input = param1;
	floatinlet_new(&x->x_obj, &x->input); // passive inlets
*/

	x->out_stage_1 = outlet_new(&x->x_obj, &s_float);
	x->out_stage_1_3 = outlet_new(&x->x_obj, &s_float);
	x->out_stage_1_5 = outlet_new(&x->x_obj, &s_float);

	x->out_stage_2 = outlet_new(&x->x_obj, &s_float);
	x->out_stage_2_3 = outlet_new(&x->x_obj, &s_float);
	x->out_stage_2_5 = outlet_new(&x->x_obj, &s_float);

	x->out_stage_3 = outlet_new(&x->x_obj, &s_float);
	x->out_stage_3_3 = outlet_new(&x->x_obj, &s_float);
	x->out_stage_3_5 = outlet_new(&x->x_obj, &s_float);

	x->out_stage_4 = outlet_new(&x->x_obj, &s_float);
	x->out_stage_4_3 = outlet_new(&x->x_obj, &s_float);
	x->out_stage_4_5 = outlet_new(&x->x_obj, &s_float);

	x->out_stage_5 = outlet_new(&x->x_obj, &s_float);
	x->out_stage_5_3 = outlet_new(&x->x_obj, &s_float);
	x->out_stage_5_5 = outlet_new(&x->x_obj, &s_float);

	x->out_stage_6 = outlet_new(&x->x_obj, &s_float);
	x->out_stage_6_3 = outlet_new(&x->x_obj, &s_float);
	x->out_stage_6_5 = outlet_new(&x->x_obj, &s_float);

	x->out_stage_7 = outlet_new(&x->x_obj, &s_float);
	x->out_stage_7_3 = outlet_new(&x->x_obj, &s_float);
	x->out_stage_7_5 = outlet_new(&x->x_obj, &s_float);

	x->out_stage_8 = outlet_new(&x->x_obj, &s_float);
	x->out_stage_8_3 = outlet_new(&x->x_obj, &s_float);
	x->out_stage_8_5 = outlet_new(&x->x_obj, &s_float);


  /*
   * return the pointer to the class - this is mandatory
   * if you return "0", then the object-creation will fail
   */
  return (void *)x;
}

void ph_pitchperfect_calculate(ph_pitchperfect *x,float keynote)
{
	post("we are here");
	post("Keynote: \"%.1f\"", keynote);

	float grSek = keynote *9/8;  // D
	float grTerz = keynote *5/4; // E
	float quarte = keynote* 4/3; // F
	float quinte = keynote* 3/2; // G
	float grSext = keynote* 5/3; // A
	float grSept = keynote *15/8; //H
	float oktave = keynote *2;    //C
	//verhältnisse nach der reinen stimmung

	outlet_float(x->out_stage_1, keynote);
	outlet_float(x->out_stage_1_3, grTerz);
	outlet_float(x->out_stage_1_5, quinte);

	outlet_float(x->out_stage_2, grSek);
	outlet_float(x->out_stage_2_3, quarte);
	outlet_float(x->out_stage_2_5, grSext);

	outlet_float(x->out_stage_3, grTerz);
	outlet_float(x->out_stage_3_3, quinte);
	outlet_float(x->out_stage_3_5, grSept);

	outlet_float(x->out_stage_4, quarte);
	outlet_float(x->out_stage_4_3, grSext);
	outlet_float(x->out_stage_4_5, oktave);

	outlet_float(x->out_stage_5, quinte);
	outlet_float(x->out_stage_5_3, grSept);
	outlet_float(x->out_stage_5_5, grSek);

	outlet_float(x->out_stage_6, grSext);
	outlet_float(x->out_stage_6_3, oktave);
	outlet_float(x->out_stage_6_5, grTerz);

	outlet_float(x->out_stage_7, grSept);
	outlet_float(x->out_stage_7_3, grSek);
	outlet_float(x->out_stage_7_5, quinte);

	outlet_float(x->out_stage_8, oktave);
	outlet_float(x->out_stage_8_3, grTerz);
	outlet_float(x->out_stage_8_5, quinte);

}


/**
 * define the function-space of the class
 * within a single-object external the name of this function is special
 */
void ph_pitchperfect_setup(void) {
  /* create a new class */
	ph_pitchperfect_class = class_new(gensym("ph_pitchperfect"),        /* the object's name is "helloworld" */
			       (t_newmethod)ph_pitchperfect_new, /* the object's constructor is "helloworld_new()" */
			       0,                           /* no special destructor */
			       sizeof(ph_pitchperfect),        /* the size of the data-space */
			       CLASS_DEFAULT,               /* a normal pd object */
			       0);                          /* no creation arguments */

  /* attach functions to messages */
  /* here we bind the "helloworld_bang()" function to the class "helloworld_class()" -
   * it will be called whenever a bang is received
   */
  class_addbang(ph_pitchperfect_class, ph_pitchperfect_bang);
  class_addmethod(ph_pitchperfect_class, (t_method)ph_pitchperfect_calculate, gensym("keynote"), A_DEFFLOAT, 0);

}
