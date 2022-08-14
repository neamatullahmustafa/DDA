#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
float xs = 0 , ys = 0 , xe = 0 , ye = 0 ;
int integar ( float num )
{
    return ( num + 0.5 );
}
void dda_line(void)
{
    float dx = xe - xs , dy = ye - ys , xinc , yinc , x = xs , y = ys ;
    float m = dy / dx ;
    if ( abs ( m ) <= 1 )
    {
        xinc = 1 ;
        yinc = m ;
    }
    else if ( abs ( m ) > 1 && m > 0 )
    {
        xinc = 1/m ;
        yinc = 1 ;
    }
    else if ( abs ( m ) > 1 && m < 0 )
    {
        xinc = - 1/m ;
        yinc = - 1 ;
    }
    float step = ( abs ( m ) < 1)?( abs ( dx ) ) : ( abs ( dy ) );
    glClear ( GL_COLOR_BUFFER_BIT ) ;
    glBegin ( GL_POINTS ) ;
    glVertex2d ( x , y ) ;
    for ( int i = 0 ; i < step ; i++ )
    {
        x += xinc ;
        y += yinc ;
        glVertex2d ( integar ( x ) , integar ( y ) ) ;
    }
    glEnd ( ) ;
    glFlush ( ) ;
}
    void Init ( )
    {
    glClearColor ( 0.0 , 0.0 , 0.0 , 0 ) ;
    glColor3f ( 1.0 , 0.0 , 0.0 ) ;
    gluOrtho2D ( 0 , 500 , 0 , 500);
    }
int main ( int argc , char **argv )
{
    printf ( "draw line DDA \n" ) ;
    printf ( "please enter start point \n" ) ;
    scanf ( "%f%f" , &xs , &ys ) ;
    printf ( "please enter end point \n" ) ;
    scanf ( "%f%f" , &xe , &ye ) ;
    glutInit (&argc , argv) ;
    glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB ) ;
    glutInitWindowPosition ( 0 , 0 ) ;
    glutInitWindowSize ( 500 , 500) ;
    glutCreateWindow ( " dda_line " ) ;
    Init ( ) ;
    glutDisplayFunc( dda_line ) ;
    glutMainLoop ( );
    return 0 ;
}
