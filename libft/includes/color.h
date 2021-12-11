/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 14:03:32 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/05 14:21:28 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

/*----------------------------COLOR----------------------------*/

//Regular text
# define __BLACK "\e[0;30m"
# define __RED "\e[0;31m"
# define __GREEN "\e[0;32m"
# define __YELLOW "\e[0;33m"
# define __BLUE "\e[0;34m"
# define __PURPLE "\e[0;35m"
# define __CYAN "\e[0;36m"
# define __WHITE "\e[0;37m"

//Regular bold text
# define __BBLACK "\e[1;30m"
# define __BRED "\e[1;31m"
# define __BGREEN "\e[1;32m"
# define __BYELLOW "\e[1;33m"
# define __BBLUE "\e[1;34m"
# define __BPURPLE "\e[1;35m"
# define __BCYAN "\e[1;36m"
# define __BWHITE "\e[1;37m"

//Regular underline text
# define __UBLACK "\e[4;30m"
# define __URED "\e[4;31m"
# define __UGREEN "\e[4;32m"
# define __UYELLOW "\e[4;33m"
# define __UBLUE "\e[4;34m"
# define __UPURPLE "\e[4;35m"
# define __UCYAN "\e[4;36m"
# define __UWHITE "\e[4;37m"

//Regular background
# define __BLACKB "\e[40m"
# define __REDB "\e[41m"
# define __GREENB "\e[42m"
# define __YELLOWB "\e[43m"
# define __BLUEB "\e[44m"
# define __PURPLEB "\e[45m"
# define __CYANB "\e[46m"
# define __WHITEB "\e[47m"

//High intensty background 
# define __BLACKHB "\e[0;100m"
# define __REDHB "\e[0;101m"
# define __GREENHB "\e[0;102m"
# define __YELLOWHB "\e[0;103m"
# define __BLUEHB "\e[0;104m"
# define __PURPLEHB "\e[0;105m"
# define __CYANHB "\e[0;106m"
# define __WHITEHB "\e[0;107m"

//High intensty text
# define __HBLACK "\e[0;90m"
# define __HRED "\e[0;91m"
# define __HGREEN "\e[0;92m"
# define __HYELLOW "\e[0;93m"
# define __HBLUE "\e[0;94m"
# define __HPURPLE "\e[0;95m"
# define __HCYAN "\e[0;96m"
# define __HWHITE "\e[0;97m"

//Bold high intensity text
# define __BHBLACK "\e[1;90m"
# define __BHRED "\e[1;91m"
# define __BHGREEN "\e[1;92m"
# define __BHYELLOW "\e[1;93m"
# define __BHBLUE "\e[1;94m"
# define __BHPURPLE "\e[1;95m"
# define __BHCYAN "\e[1;96m"
# define __BHWHITE "\e[1;97m"

//Reset
# define __RESET "\e[0m"

#endif
