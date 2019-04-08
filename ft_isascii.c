
int	  ft_isascii(int c)
{
	 unsigned char c_ch;

	 c_ch = (unsigned char)c;
	 if (c_ch)
	 {
		  return (1);
	 }
	 else
	 {
		  return (0);
	 }
}
