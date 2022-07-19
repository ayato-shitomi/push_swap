/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:00:19 by ashitomi          #+#    #+#             */
/*   Updated: 2022/07/13 16:00:19 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/////////////////////////////////////////////////////
//   INCLUDES
/////////////////////////////////////////////////////

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/////////////////////////////////////////////////////
//   DEFINES AND STRUCT
/////////////////////////////////////////////////////

# define DEPTH	5

# define ZERO 0
# define ONE 1

typedef struct s_stack
{
	int		*array;
	size_t	size;
	size_t	max_size;
}	t_stack;

typedef struct s_instruction
{
	char	*line;
	void	*next;
	void	*prev;
}	t_instruction;

typedef struct s_program
{
	t_stack			stack_a;
	t_stack			stack_b;
	t_instruction	*instr;
}	t_program;

typedef struct s_state
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_instruction	*instructions;
	t_instruction	*last_instr;
	void			*next;
}	t_state;

/////////////////////////////////////////////////////
//   PROTOTYPES
/////////////////////////////////////////////////////

// utils.c
char				*ft_strdup_char(const char *str, char stop);
int					ft_atoi_pushswap(const char *str, int *num);
int					ft_strcmp(const char *s1, const char *s2);
void				print_some(int	debug);

// free_something.c
int					free_instructions(t_instruction *instructions);
void				free_stack(t_stack *stack);
void				free_states(t_state *states);
int					free_prg(t_program *prg);

// rotate.c
void				rotate_stack(t_stack *stack);
void				reverse_rotate_stack(t_stack *stack);
t_instruction		*rotate(t_state *stt);
t_instruction		*rotate_a(t_state *stt, size_t min[2], size_t min_mvt[2]);

// align_stacks.c
void				calcul_align_a(size_t *pos, \
	size_t *mvt, t_stack *stack_a, t_stack *stack_b);
void				calcul_align_b(size_t *pos, size_t *mvt, t_stack *stack_b);
int					align_stack_a(t_program *prg);
int					align_stack_b(t_program *prg);

// instructions.c
t_instruction		*add_instruction(t_instruction **instructions, char *line);
t_instruction		*add_n_instructions(t_instruction **instructions, \
	char *line, size_t n);
t_instruction		*copy_instructions(t_instruction *instructions);
size_t				count_instructions(t_instruction *instr);

// instructions_utils.c
t_state				*new_state_instruction(t_state **states, \
	t_state *old_state, char *line);
void				execute_instructions(t_instruction *instr, \
	t_stack *stack_a, t_stack *stack_b);
t_instruction		*copy_and_concat_instructions(t_instruction **instr, \
	t_instruction *new);

// stacks.c
int					stack_contains(t_stack *stack, int num);
int					fill_stack_arg(char *arg, t_stack *stack, \
	size_t *stack_nb);
int					fill_stack(int argc, char *argv[], t_stack *stack);
int					init_stacks(int argc, char *argv[], \
	t_stack *stack_a, t_stack *stack_b);

// stacks_utils.c
size_t				count_stack_size(int argc, char *argv[]);
int					is_stack_ordered(t_stack *stack, int order);

// bruteforce.c
int					bruteforce_choice_a(t_state **new_states, \
	t_state *tmp, size_t pos[2], t_stack *stack_b);
int					reverse_rotate_bruteforce_a(t_state **new_states, \
	t_state *tmp, size_t pos[2], t_stack *stack_b);
int					bruteforce_order_a(t_program *prg);
int					rotate_bruteforce_a(t_state **new_states, \
	t_state *tmp, size_t pos[2], t_stack *stack_b);

// brutefoce_pick_check.c
int					check_bruteforce_solution(t_state *states, \
	t_state **result);
t_state				*pick_bruteforce_solution(t_state *states, \
	size_t pos[2], t_stack *stack_b);

// add_state.c
t_state				*add_state(t_state **states, t_state *state_from);

// new_empty_state.c
t_state				*new_empty_state(t_stack *stack_a, \
	t_stack *stack_b, size_t max_size);

// pushswap_utils.c
int					usage(void);
int					ft_put_err_return_one(void);
void				print_instruction(t_instruction *instr);
void				print_instructions(t_instruction *instr);

// stack_utils.c
t_stack				*copy_stack(t_stack *stack);
t_stack				*new_empty_stack(size_t max_size);

// movement.c
void				swap_stack(t_stack *stack);
void				push_stack(t_stack *stack1, t_stack *stack2);

// resolve.c
int					pick_solution(t_program *prg, t_state *states);
int					large_resolve(t_state *states);
int					resolve(t_program *prg);

// less_mvt.c
size_t				less_mvt_at_begin(size_t minimal_mvt, \
	size_t *min_mvt, t_stack *stack_a, t_stack *stack_b);
size_t				less_mvt_at_end(size_t minimal_mvt, \
	size_t *min_mvt, t_stack *stack_a, t_stack *stack_b);

// main.c
int					create_states_resolution(t_state **states);
int					can_pb(t_stack *stack_a, t_stack *stack_b);
size_t				closer_pos_to_inf(int nb, t_stack *stack);
int					realign_and_fill_a(t_program *prg);
int					main(int ac, char **av);

// resolve_utils.c
int					if_do_ra(t_program *prg);
int					if_do_rra(t_program *prg);
int					if_do_rra_two(t_program *prg);
int					resolve_return(t_program *prg);

// second_resolve.c
int					second_resolve(t_program *prg);
int					print_ins_and_some(t_program *prg, int debug);
void				print_ins_and_some_and_free(t_program *prg, int debug);
int					instr_null(t_program *prg);

// second_resolv_utils.c
void				print_pbrb(void);
int					print_pb_rb_with_num(int i);
int					print_pa_ra_with_num(int i);

// check_ac.c
int					check_ac(int ac);
int					write_err_ac(int ac, char **av);

// other libft
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlen(const char *s);
void				ft_putstr_fd(char *s, int fd);
void				*ft_memset(void *dst, int c, size_t n);
char				*ft_strdup(const char *str);
void				*ft_calloc(size_t count, size_t size);
void				ft_bzero(void *s, size_t n);
char				*ft_itoa(int n);

#endif
