/**
 * Created by ikaros on 2015/3/24.
 */
public class P2 {
    int height, shape;

    public P2() {
    }

    public P2(int height) {

        this.height = height;
    }

    public P2(int height, int type) {

        this.height = height;

        this.shape = type;
    }
    
    public int getHeight() {
        return height;
    }

    public void setHeight(int height) {
        this.height = height;
    }

    public int getShape() {
        return shape;
    }

    public void setShape(int shape) {
        this.shape = shape;
    }
    
    private void prchar(String c, int n) {for(int i = 0; i < n; i++) System.out.print(c);}
    
    public void draw()
    {
        if(shape == 1) //Triangle
        {
            for (int i = 0; i < height; i++)
            {
                prchar(" ", height -i-1);
                prchar("*", 2*i+1);
                prchar(" ", height -i-1);
                System.out.println();
            }
        }
        else
        {
            for (int i = 0; i < height; i++)
            {
                prchar("*", height);
                System.out.println();
            }
        }
    }
    public void drawAll() {
        for (int i = 0; i < height; i++)
        {
            prchar(" ", height -i-1);
            prchar("*", 2*i+1);
            prchar(" ", height -i-1);
            System.out.println();
        }
        for (int i = 0; i < height; i++)
        {
            prchar("*", height);
            System.out.println();
        }
    }
}
