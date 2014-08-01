#include <gtk/gtk.h>

gboolean draw_button(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
	if(gtk_widget_has_focus(widget)) {
		double r = 0;
		double g = 102.0/255.0;
		double b = 1.0;
		cairo_rectangle (
			cr,
			0, 0,
			gtk_widget_get_allocated_width(widget),
			gtk_widget_get_allocated_height(widget));
		cairo_set_source_rgba (cr, r, g, b, 0.25);
		cairo_fill (cr);

		// cairo_set_line_width (cr, 2);
		// cairo_set_source_rgba (cr, r, g, b, 0.5);
		// cairo_rectangle (cr, 0, 0, 
		// 	gtk_widget_get_allocated_width(widget),
		// 	gtk_widget_get_allocated_height(widget));
		// cairo_stroke (cr);
	} else {
		// do nothing
	}
			
	return FALSE;
}

int
main( int    argc,
	  char **argv )
{
	/* Vars */
	GtkWidget  *window;
	GtkWidget  *button1, *button2, *button3;
	GtkBuilder *builder;
	GError     *error = NULL;
	// gboolean	*selected = (gboolean*)g_malloc(sizeof(gboolean));
	// *selected = FALSE;

	/* Initialization */
	gtk_init( &argc, &argv );

	/* Create builder and load UI file */
	builder = gtk_builder_new();
	if( ! gtk_builder_add_from_file( builder, "../test_gui.glade", &error ) )
	{
		g_print( "Error occured while loading UI file!\n" );
		g_print( "Message: %s\n", error->message );
		g_free( error );

		return( 1 );
	}

	/* Get main window and connect signals */
	window = GTK_WIDGET( gtk_builder_get_object( builder, "window_main" ) );
	button1 = GTK_WIDGET( gtk_builder_get_object( builder, "button1" ) );
	button2 = GTK_WIDGET( gtk_builder_get_object( builder, "button2" ) );
	button3 = GTK_WIDGET( gtk_builder_get_object( builder, "button3" ) );
	gtk_builder_connect_signals( builder, NULL );

	g_signal_connect_after (
		button1,
		"draw",
		G_CALLBACK (draw_button),
		NULL
	);
	g_signal_connect_after (
		button2,
		"draw",
		G_CALLBACK (draw_button),
		NULL
	);
	g_signal_connect_after (
		button3,
		"draw",
		G_CALLBACK (draw_button),
		NULL
	);

	/* Destroy builder */
	g_object_unref( G_OBJECT( builder ) );

	/* Show main window and start main loop */
	gtk_widget_show( window );
	gtk_main();

	return( 0 );
}

