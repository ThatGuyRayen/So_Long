#ifndef SO_LONG_H
# define SO_LONG_H

#define IMG_H 400
#define IMG_W 400


# include "libft/libft.h"
#include "mlx.h"
#include <X11/keysym.h>

typedef struct s_mlx_data {
	void	*mlx_ptr;
	void	*win_ptr;
}		t_mlx_data;

int	initialize_mlx(t_mlx_data **ptr);
int	handle_input(int keysym, t_mlx_data *ptr);

#endif
