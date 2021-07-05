#include <mlx.h>

typedef struct  s_mlx 
{
    void        *img;
    char        *addr;
    int         bpp;
    int         line_length;
    int         endian;
}               t_mlx;

// int     render_next_frame(t_data *img);

void            my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
    *(unsigned int*)dst = color;
}

int             main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_mlx  img;
    int x;
    int y;
 
    y = 0;
    x = 0;
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "miniRT");
    img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length,
                                 &img.endian);
    while (x < 1920)
    {
        while (y < 1080)
        {
            my_mlx_pixel_put(&img, x, y, 0xFFFFFFFF);
            y++;
        }
        y = 0;
        x++;
    }
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    // mlx_loop_hook(mlx, render_next_frame, &img);
    mlx_loop(mlx);
}

    // ПЕЧАТЬ ЧЕРЕЗ ПИКСЕЛЬ
    // while (y < 1000)
    // {
    //     m = 0;
    //     while (x < 1000)
    //     {
    //         if (x%2 == 0)
    //             my_mlx_pixel_put(&img, x, y, 0x00000000);
    //         else
    //             my_mlx_pixel_put(&img, x, y, 0x00FF0000);
    //         x++;
    //     }
    //     x = 100;
    //     y++;
    // }