void
kernel_main(void)
{
	char *video_mem = (char*)0xB8000;

	*video_mem = 'Z';
}
