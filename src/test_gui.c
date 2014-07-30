#include <gtk/gtk.h>

int
main( int    argc,
	  char **argv )
{
	/* Vars */
	GtkWidget  *window;
	GtkBuilder *builder;
	GError     *error;

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
	gtk_builder_connect_signals( builder, NULL );

	/* Destroy builder */
	g_object_unref( G_OBJECT( builder ) );

	/* Show main window and start main loop */
	gtk_widget_show( window );
	gtk_main();

	return( 0 );
}