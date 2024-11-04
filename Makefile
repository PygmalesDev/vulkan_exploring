CFLAGS  = -std=c11
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

VulkanTest: code/main.c
	gcc $(CFLAGS) -o VulkanTest code/main.c code/run.c code/instances.c code/logger.c $(LDFLAGS)

.PHONY: test clean

test: VulkanTest
	./VulkanTest

clean:
	rm -f VulkanTest
