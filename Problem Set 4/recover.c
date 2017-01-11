/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
#include <cs50.h>
#include <stdio.h>
#include <stdint.h>


typedef uint8_t byte;

int main(void)
{
    
    // open file
    
    FILE* inptr = fopen("card.raw", "r");
    
    // check
    if (inptr == NULL)
    {
        fclose(inptr);
        printf("could not open file");
        return 1;
    }
    
    
    
    byte buf[512];
    int jpg = 0;
    char jpgname[10];
    FILE* outptr = NULL;
    
    //to do
    while(!feof(inptr))
    {
//          fread(buf, sizeof(buf), 1, inptr);
        //find jpg
        if (buf[0] == 0xff 
        && buf[1] == 0xd8 
        && buf[2] == 0xff 
        && (buf[3] == 0xe0 || buf[3] == 0xe1))
        {
            if (outptr != NULL)
            {
            fclose(outptr);
            }
            
            //create new file
            sprintf(jpgname, "%03d.jpg", jpg);
            
            outptr = fopen(jpgname, "w");
            
            jpg++;
            
            fwrite(buf, sizeof(buf), 1, outptr);
            
        }
            else if (jpg > 0)
            {
                fwrite(buf, sizeof(buf), 1, outptr);
            }
        
        fread(buf, sizeof(buf), 1, inptr);
        
    }
        fclose(inptr);
        return 0;
        
}
    
    
    
    
    
    

